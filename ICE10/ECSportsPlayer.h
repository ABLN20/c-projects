#ifndef _EC_SPORTS_PLAYER_H
#define _EC_SPORTS_PLAYER_H

// ********************************************
// Sports Tournament
class ECTournament
{
public:
ECTournament(int mon, int mr) : month(mon), minRank(mr) {}
int GetMonth() const { return month; }
int GetMinRank() const { return minRank; }

private:
int month;
int minRank;
};

// ********************************************
// Generic player
class ECSportsPlayer
{
friend class ECSportsPlayerDec;
public:
virtual ~ECSportsPlayer() {}
virtual bool CanPlay(ECTournament &tr) const
{
if( Neg(tr) == true )
{
return false;
}
return Pos(tr);
}

protected:

// return true if there is a POSITIVE rule saying can play
virtual bool Pos(ECTournament &tr) const
{
return false;
}

// return true if there is a NEGATIE rule saying cannot play
virtual bool Neg(ECTournament &tr) const
{
return false;
}

};

// ********************************************
// Ranked player
class ECSportsPlayerRanked : public ECSportsPlayer
{
public:
ECSportsPlayerRanked(int r) : rank(r) {}

protected:

// return true if there is a POSITIVE rule saying can play
virtual bool Pos(ECTournament &tr) const
{
return rank <= tr.GetMinRank();
}

private:
int rank;
};

// ********************************************
// Decorated player: for various conditions, e.g. wildcard, injury, etc
class ECSportsPlayerDec : public ECSportsPlayer
{
public:
ECSportsPlayerDec( ECSportsPlayer &sp ) : sp(sp) {}

protected:

// return true if there is a POSITIVE rule saying can play
virtual bool Pos(ECTournament &tr) const
{
return sp.Pos(tr);
}

// return true if there is a NEGATIE rule saying cannot play
virtual bool Neg(ECTournament &tr) const
{
return sp.Neg(tr);
}

private:
ECSportsPlayer &sp;
};

// ********************************************
// Wildcard player: qualify for any tournament
class ECSportsPlayerWildcard : public ECSportsPlayerDec
{
public:
ECSportsPlayerWildcard(ECSportsPlayer &playerOrig) : ECSportsPlayerDec(playerOrig) {}

protected:

// return true if there is a POSITIVE rule saying can play
virtual bool Pos(ECTournament &tr) const
{
return true;
}
};

// ********************************************
// Displined player: cannot attend any tournament during the period of probation
class ECSportsPlayerDisciplined : public ECSportsPlayerDec
{
public:
ECSportsPlayerDisciplined(ECSportsPlayer &playerOrig, int mStart, int mEnd) : ECSportsPlayerDec(playerOrig),
mStart(mStart), mEnd(mEnd) {}

protected:

// return true if there is a NEGATIE rule saying cannot play
virtual bool Neg(ECTournament &tr) const
{
// return true (NEG in effect) if tournament is held during the displinary period
if( tr.GetMonth() >= mStart && tr.GetMonth() <= mEnd )
{
return true;
}
// to ensure checking of other NEG rule in effect of player being decorated
return ECSportsPlayerDec :: Neg(tr);
}

private:
int mStart;
int mEnd;
};

// ********************************************
// Injured player: cannot attend any tournament during the period of injury(injury occurs at a single month)
class ECSportsPlayerInjured : public ECSportsPlayerDec
{
public:
ECSportsPlayerInjured(ECSportsPlayer &playerOrig, int m) : ECSportsPlayerDec(playerOrig),
m(m) {}

protected:

// return true if there is a NEGATIE rule saying cannot play
virtual bool Neg(ECTournament &tr) const
{
// return true (NEG in effect) if tournament is held during the displinary period
if( tr.GetMonth() == m )
{
return true;
}
// to ensure checking of other NEG rule in effect of player being decorated
return ECSportsPlayerDec :: Neg(tr);
}

private:
int m;
};

#endif