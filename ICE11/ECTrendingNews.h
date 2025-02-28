#ifndef EC_TRENDING_NEWS_H
#define EC_TRENDING_NEWS_H

#include <algorithm>
#include <vector>


// Subscriber interface. DON'T CHANGE THIS
class ECSubscriber
{
public:
	virtual ~ECSubscriber() {}
    virtual void Update() = 0;
    virtual int ContractCost() const = 0;
};

// This is the subject
class ECTrendingNews
{
public:
	ECTrendingNews() : balance(0) {}
	~ECTrendingNews() {}
	// add a subscriber
	void Subscribe(ECSubscriber *pSub)
	{
		ReceivePayment(pSub->ContractCost());
		listSubs.push_back(pSub);
	}
	// remove a subscriber
	void UnSubscribe(ECSubscriber *pSub)
	{
		listSubs.erase(std::remove(listSubs.begin(), listSubs.end(), pSub), listSubs.end());
	}
	// Notify news is available for view
	void Notify()
	{
		for(auto x: listSubs)
		{
			x->Update();
		}
	}
	// receive payment (assume in whole dollar)
	void ReceivePayment(int amount)
	{
		balance+=amount;
	}
	// Get total revenue received
	int GetTotRevenue() const {return balance;}
	
private:
	std::vector<ECSubscriber*> listSubs;
	int balance;
};

// pay-per click subscriber
class ECPayPerClickSubscriber : public ECSubscriber
{
public:
	ECPayPerClickSubscriber(ECTrendingNews &news) : news(news) {}
	virtual void Update()
	{
		news.ReceivePayment(1);
	}
	virtual int ContractCost() const {return 0; }
private:
	ECTrendingNews &news;
};

// Contract subscriber
class ECContractSubscriber : public ECSubscriber
{
public:
	ECContractSubscriber(ECTrendingNews &news) : news(news) {}
	virtual void Update() {}
	virtual int ContractCost() const { return 100; }
private:
    ECTrendingNews &news;
};



#endif
