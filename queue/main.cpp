#include "queue.hpp"
#include "../list/list.hpp"
#include <deque>
#include <iostream>

int     main()
{
    std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          CONSTRUCTEUR" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
        std::deque<int> mydeck (3,100);        // deque with 3 elements
        ft::list<int> mylist (2,200);         // list with 2 elements

        ft::queue<int> first;                 // empty queue
        ft::queue<int> second (mydeck);       // queue initialized to copy of deque

        ft::queue<int,ft::list<int> > third; // empty queue with list as underlying container
        ft::queue<int,ft::list<int> > fourth (mylist);

        std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "size of first: 0\nsize of second: 3\nsize of third: 0\nsize of fourth: 2"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

        std::cout << "size of first: " << first.size() << '\n';
        std::cout << "size of second: " << second.size() << '\n';
        std::cout << "size of third: " << third.size() << '\n';
        std::cout << "size of fourth: " << fourth.size() << '\n';
	}

    std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          EMPTY" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
        ft::queue<int> myqueue;
        int sum (0);

        for (int i=1;i<=10;i++) myqueue.push(i);

        while (!myqueue.empty())
        {
            sum += myqueue.front();
            myqueue.pop();
        }

        std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "total: 55"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

        std::cout << "total: " << sum << '\n';
	}

    std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          SIZE" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
        ft::queue<int> myints;

        std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "0. size: 0\n1. size: 5\n2. size: 4"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

        std::cout << "0. size: " << myints.size() << '\n';

        for (int i=0; i<5; i++) myints.push(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.pop();
        std::cout << "2. size: " << myints.size() << '\n';
	}

    std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          FRONT" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
        ft::queue<int> myqueue;

        myqueue.push(77);
        myqueue.push(16);

        myqueue.front() -= myqueue.back();    // 77-16=61

        std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "myqueue.front() is now 61"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

        std::cout << "myqueue.front() is now " << myqueue.front() << '\n';
	}

    std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          BACK" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
        ft::queue<int> myqueue;

        myqueue.push(12);
        myqueue.push(75);   // this is now the back

        myqueue.back() -= myqueue.front();

        std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "myqueue.back() is now 63"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

        std::cout << "myqueue.back() is now " << myqueue.back() << '\n';
	}

    std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          PUSH" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
        ft::queue<int> myqueue;
        int myint;

        std::cout << "Please enter some integers (enter 0 to end):\n";

        do {
            std::cin >> myint;
            myqueue.push (myint);
        } while (myint);

        std::cout << "SIZE = " << myqueue.size() << std::endl;
        std::cout << "myqueue contains: ";
        while (!myqueue.empty())
        {
            std::cout << ' ' << myqueue.front();
            myqueue.pop();
        }
        std::cout << "\nSIZE apres suppression = " << myqueue.size() << std::endl;
	}

    std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          POP" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
        ft::queue<int> myqueue;
        int myint;

        std::cout << "Please enter some integers (enter 0 to end):\n";

        do {
            std::cin >> myint;
            myqueue.push (myint);
        } while (myint);

        std::cout << "SIZE = " << myqueue.size() << std::endl;
        std::cout << "myqueue contains: ";
        while (!myqueue.empty())
        {
            std::cout << ' ' << myqueue.front();
            myqueue.pop();
        }
        std::cout << "\nSIZE apres suppression = " << myqueue.size() << std::endl;
	}

    return 0;
}