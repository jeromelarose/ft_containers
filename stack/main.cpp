#include "stack.hpp"
#include "../vector/vector.hpp"
#include <deque>

int     main()
{
    std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          CONSTRUCTEUR" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
        std::deque<int> mydeque (3,100);          // deque with 3 elements
        ft::vector<int> myvector (2,200);        // vector with 2 elements

        ft::stack<int> first;                    // empty stack
        ft::stack<int> second(mydeque);         // stack initialized to copy of deque

        ft::stack<int,ft::vector<int> > third;  // empty stack using vector
        ft::stack<int,ft::vector<int> > fourth (myvector);

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
        ft::stack<int> mystack;
        int sum (0);

        for (int i=1;i<=10;i++) mystack.push(i);

        while (!mystack.empty())
        {
            sum += mystack.top();
            mystack.pop();
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
        ft::stack<int> myints;

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
	std::cout << "          TOP" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
    {
        ft::stack<int> mystack;

        mystack.push(10);
        mystack.push(20);

        mystack.top() -= 5;

        std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mystack.top() is now 15"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

        std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}

    std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          PUSH" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
    {
        ft::stack<int> mystack;

        for (int i=0; i<5; ++i) mystack.push(i);

        std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "Popping out elements... 4 3 2 1 0"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

        std::cout << "Popping out elements...";
        while (!mystack.empty())
        {
            std::cout << ' ' << mystack.top();
            mystack.pop();
        }
        std::cout << '\n';
	}

    std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          POP" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
    {
         ft::stack<int> mystack;

        for (int i=0; i<5; ++i) mystack.push(i);

        std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "Popping out elements... 4 3 2 1 0"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

        std::cout << "Popping out elements...";
        while (!mystack.empty())
        {
            std::cout << ' ' << mystack.top();
            mystack.pop();
        }
        std::cout << '\n';
	}
    return 0;
}