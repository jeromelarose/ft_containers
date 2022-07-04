#include <math.h>       /* fabs */
#include "vector.hpp"
#include <iostream>

int     main()
{

    std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          CONSTRUCTEUR" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
        // constructors used in the same order as described above:
        ft::vector<int> first;                                // empty vector of ints
        ft::vector<int> second (4,100);                       // four ints with value 100
        ft::vector<int> third (second.begin(),second.end());  // iterating through second
        ft::vector<int> fourth (third);                       // a copy of third

        // the iterator constructor can also be used to construct from arrays:
        int myints[] = {16,2,77,29};
        ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

        std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "The contents of fifth are: 16 2 77 29"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

        std::cout << "The contents of fifth are:";
        for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
            std::cout << ' ' << *it;

        std::cout << "\nThe contents of fifth are: ";
		ft::vector<int>::iterator it;
		for (it = --fifth.end(); it != fifth.begin(); --it)
			std::cout << *it << ' ';
		std::cout << *it << ' ';
		std::cout << "\nsize vector = " << fifth.size() << std::endl;

	}

    std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          OPERATOR=" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

        ft::vector<int> foo (3,0);
        ft::vector<int> bar (5,0);

        bar = foo;
        foo = ft::vector<int>();

        std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "Size of foo: 0\nSize of bar: 3"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

        std::cout << "Size of foo: " << int(foo.size()) << '\n';

        std::cout << "The contents foo:";
        for (ft::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
            std::cout << ' ' << *it;
        
        std::cout << "\nSize of bar: " << int(bar.size()) << '\n';

        std::cout << "The contents bar:";
        ft::vector<int>::iterator it;
        for (ft::vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
            std::cout << ' ' << *it;

        std::cout << "\nThe contents bar: ";
		for (it = --bar.end(); it != bar.begin(); --it)
			std::cout << *it << ' ';
		std::cout << *it << ' ' << std::endl;

	}

    std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          BEGIN" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

        ft::vector<int> myvector;
        for (int i=1; i<=5; i++) myvector.push_back(i);

        std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "myvector contains: 1 2 3 4 5"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

        std::cout << "myvector contains:";
        for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
            std::cout << ' ' << *it;

        std::cout << "\nmyvector contains:";
        ft::vector<int>::iterator it;
		for (it = --myvector.end(); it != myvector.begin(); --it)
            std::cout << ' ' << *it;
        std::cout << ' ' << *it << std::endl;
		std::cout << "\nsize vector = " << myvector.size() << std::endl;

	}

    std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          END" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

        ft::vector<int> myvector;
        for (int i=1; i<=5; i++) myvector.push_back(i);

        std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "myvector contains: 1 2 3 4 5"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

        std::cout << "myvector contains:";
        for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
            std::cout << ' ' << *it;

        std::cout << "\nmyvector contains:";
        ft::vector<int>::iterator it;
		for (it = --myvector.end(); it != myvector.begin(); --it)
            std::cout << ' ' << *it;
        std::cout << ' ' << *it << std::endl;
		std::cout << "\nsize vector = " << myvector.size() << std::endl;

	}

    std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          RBEGIN " << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

        ft::vector<int> myvector (5);  // 5 default-constructed ints

        int i=0;

        ft::vector<int>::reverse_iterator rit = myvector.rbegin();
        for (; rit!= myvector.rend(); ++rit)
            *rit = ++i;

        std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "5 4 3 2 1"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

        std::cout << "myvector contains:";
        for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
            std::cout << ' ' << *it;

        std::cout << "\nmyvector contains:";
        for (ft::vector<int>::reverse_iterator it = myvector.rbegin(); it != myvector.rend(); ++it)
            std::cout << ' ' << *it;
        
		std::cout << "\nsize vector = " << myvector.size() << std::endl;

	}

    std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          REND" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

        ft::vector<int> myvector (5);  // 5 default-constructed ints

        ft::vector<int>::reverse_iterator rit = myvector.rbegin();

        int i=0;
        for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
            *rit = ++i;

        std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "5 4 3 2 1"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

        std::cout << "myvector contains:";
        for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
            std::cout << ' ' << *it;

        std::cout << "\nmyvector contains:";
        for (ft::vector<int>::reverse_iterator it = myvector.rbegin(); it != myvector.rend(); ++it)
            std::cout << ' ' << *it;
        
		std::cout << "\nsize vector = " << myvector.size() << std::endl;

	}

    std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          SIZE" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

        std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "0. size: 0\n1. size: 10\n2. size: 20\n3. size: 19"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

        ft::vector<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';

        for (int i=0; i<10; i++) myints.push_back(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.insert (myints.end(),10,100);
        std::cout << "2. size: " << myints.size() << '\n';

        myints.pop_back();
        std::cout << "3. size: " << myints.size() << '\n';

        std::cout << "myvector contains:";
		for (ft::vector<int>::iterator it=myints.begin(); it != myints.end(); ++it)
			std::cout << ' ' << *it;

		ft::vector<int>::iterator it;
		std::cout << "\nmyvector contains:";
		for (it = --myints.end(); it != myints.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it << std::endl;

	}

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

    std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          MAX_SIZE" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

        ft::vector<int> myvector;

        // set some content in the vector:
        for (int i=0; i<100; i++) myvector.push_back(i);

        std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "size: 100\ncapacity: 128\nmax_size: La valeur que allocateur peux allouer"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

        std::cout << "size: " << myvector.size() << "\n";
        std::cout << "capacity: " << myvector.capacity() << "\n";
        std::cout << "max_size: " << myvector.max_size() << "\n";

        std::cout << "myvector contains:";
        for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
            std::cout << ' ' << *it;

        std::cout << "\nmyvector contains:";
        for (ft::vector<int>::reverse_iterator it = myvector.rbegin(); it != myvector.rend(); ++it)
            std::cout << ' ' << *it;
        
		std::cout << "\nsize vector = " << myvector.size() << std::endl;

	}

    std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          RESIZE" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::vector<int> myvector;

		// set some initial content:
		for (int i=1; i<10; ++i) myvector.push_back(i);

		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);

		std::cout << "\033[37m"<< std::endl;
		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "myvector contains: 1 2 3 4 5 100 100 100 0 0 0 0"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "myvector contains:";
		for (ft::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << "\nmyvector contains:";
		ft::vector<int>::iterator it;
		for (it = --myvector.end(); it!=myvector.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize vector = " << myvector.size() << std::endl;

	}

	 std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          CAPACITY" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

        ft::vector<int> myvector;

        // set some content in the vector:
        for (int i=0; i<100; i++) myvector.push_back(i);

        std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "size: 100\ncapacity: 128\nmax_size: La valeur que allocateur peux allouer"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

        std::cout << "size: " << myvector.size() << "\n";
        std::cout << "capacity: " << myvector.capacity() << "\n";
        std::cout << "max_size: " << myvector.max_size() << "\n";

        std::cout << "myvector contains:";
        for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
            std::cout << ' ' << *it;

        std::cout << "\nmyvector contains:";
        for (ft::vector<int>::reverse_iterator it = myvector.rbegin(); it != myvector.rend(); ++it)
            std::cout << ' ' << *it;
        
		std::cout << "\nsize vector = " << myvector.size() << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          EMPTY" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		
		ft::vector<int> myvector;
		int sum (0);

		for (int i=1;i<=10;++i) myvector.push_back(i);

		while (!myvector.empty())
		{
			sum += myvector.back();
     		myvector.pop_back();
		}

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "total: 55"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

  		std::cout << "total: " << sum << '\n';
		  
		std::cout << "myvector backwards:";
		for (ft::vector<int>::reverse_iterator rit=myvector.rbegin(); rit!=myvector.rend(); ++rit)
		std::cout << ' ' << *rit;

		std::cout << "\nsize vector = " << myvector.size() << std::endl;

		std::cout << '\n';
	
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          RESERVE" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		
		ft::vector<int>::size_type sz;

		ft::vector<int> foo;
		sz = foo.capacity();

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "making foo grow:\ncapacity changed: 1\ncapacity changed: 2\ncapacity changed: 4\ncapacity changed: 8 " << std::endl;
		std::cout << "capacity changed: 16\ncapacity changed: 32\ncapacity changed: 64\ncapacity changed: 128\nmaking bar grow:\ncapacity changed: 100" << std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "making foo grow:\n";
		for (int i=0; i<100; ++i)
		{
			foo.push_back(i);
			if (sz!=foo.capacity())
			{
				sz = foo.capacity();
				std::cout << "capacity changed: " << sz << '\n';
			}
		}

		ft::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);   // this is the only difference with foo above
		std::cout << "making bar grow:\n";
		for (int i=0; i<100; ++i)
		{
			bar.push_back(i);
			if (sz!=bar.capacity())
			{
				sz = bar.capacity();
				std::cout << "capacity changed: " << sz << '\n';
			}
		}
	
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          OPERATOR[]" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		
		ft::vector<int> myvector (10);   // 10 zero-initialized elements

		ft::vector<int>::size_type sz = myvector.size();

		// assign some values:
		for (unsigned i=0; i<sz; i++) myvector[i]=i;

		// reverse vector using operator[]:
		for (unsigned i=0; i<sz/2; i++)
		{
			int temp;
			temp = myvector[sz-1-i];
			myvector[sz-1-i]=myvector[i];
			myvector[i]=temp;
		}

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "myvector contains: 9 8 7 6 5 4 3 2 1 0"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "myvector contains:";
		for (unsigned i=0; i<sz; i++)
			std::cout << ' ' << myvector[i];

		std::cout << "\nsize vector = " << myvector.size() << std::endl;
	
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          AT" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::vector<int> myvector (10);   // 10 zero-initialized ints

		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i;

		std::cout << "myvector contains: 0 1 2 3 4 5 6 7 8 9"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector.at(i);

		std::cout << "\nsize vector = " << myvector.size() << std::endl;
	
	}


	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          FRONT" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::vector<int> myvector;

		myvector.push_back(78);
		myvector.push_back(16);

		// now front equals 78, and back 16

		myvector.front() -= myvector.back();

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "myvector.front() is now 62"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "myvector.front() is now " << myvector.front() << std::endl;
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          BACK" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::vector<int> myvector;

		myvector.push_back(10);

		while (myvector.back() != 0)
		{
			myvector.push_back ( myvector.back() -1 );
		}

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "myvector contains: 10 9 8 7 6 5 4 3 2 1 0"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			std::cout << ' ' << myvector[i];

		std::cout << "\nmyvector contains:";
		ft::vector<int>::iterator it;
		for (it = --myvector.end(); it!=myvector.begin() ; --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;

		std::cout << "\nsize vector = " << myvector.size() << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          ASSIGN" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::vector<int> first;
		ft::vector<int> second;
		ft::vector<int> third;

		first.assign (7,100);             // 7 ints with a value of 100

		ft::vector<int>::iterator it;
		it=first.begin()+1;

		second.assign (it,first.end()-1); // the 5 central values of first

		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);   // assigning from array.

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "Size of first: 7\nSize of second: 5\nSize of third: 3"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
		std::cout << "Size of third: " << int (third.size()) << '\n';

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          PUSH_BACK" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::vector<int> myvector;
		int myint;

		std::cout << "Please enter some integers (enter 0 to end):\n";

		do {
			std::cin >> myint;
			myvector.push_back (myint);
		} while (myint);

		std::cout << "myvector stores " << myvector.size() << " numbers.\n";

		std::cout << "myvector contains:";
		for (ft::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << "\nmyvector contains:";
		ft::vector<int>::iterator it;
		for (it = --myvector.end(); it!=myvector.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize vector = " << myvector.size() << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          POP_BACK" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::vector<int> myvector;
		int sum (0);
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		while (!myvector.empty())
		{
			sum+=myvector.back();
			myvector.pop_back();
		}

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "The elements of myvector summed 600"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "The elements of myvector summed " << sum << '\n';
		std::cout << "myvector contains:";
		for (ft::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << "\nsize vector = " << myvector.size() << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          INSERT" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::vector<int> myvector (3,100);
		ft::vector<int>::iterator it;

		it = myvector.begin();
		it = myvector.insert ( it , 200 );

		myvector.insert (it,2,300);

		// "it" no longer valid, get a new one:
		it = myvector.begin();

		ft::vector<int> anothervector (2,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());

		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "myvector contains: 501 502 503 300 300 400 400 200 100 100 100"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "myvector contains:";
		for (it=myvector.begin(); it!=myvector.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << "\nmyvector contains:";
		for (it = --myvector.end(); it!=myvector.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize vector = " << myvector.size() << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          ERASE" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::vector<int> myvector;

		// set some values (from 1 to 10)
		for (int i=1; i<=10; i++) myvector.push_back(i);

		// erase the 6th element
		myvector.erase (myvector.begin()+5);

		// erase the first 3 elements:
		myvector.erase (myvector.begin(),myvector.begin()+3);

		std::cout << "\033[37m"<< std::endl;
		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "myvector contains: 4 5 7 8 9 10"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];

		std::cout << "\nmyvector contains:";
		ft::vector<int>::iterator it1;
		for (it1 = --myvector.end(); it1!=myvector.begin(); --it1)
			std::cout << ' ' << *it1;
		std::cout << ' ' << *it1;
		std::cout << "\nsize vector = " << myvector.size() << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          SWAP" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		std::cout << "\033[37m"<< std::endl;
		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "foo contains: 200 200 200 200 200\nbar contains: 100 100 100"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "foo contains:";
		for (unsigned i=0; i<foo.size(); i++)
			std::cout << ' ' << foo[i];

		std::cout << "\nfoo contains:";
		ft::vector<int>::iterator it;
		for (it = --foo.end(); it!=foo.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize vector = " << foo.size() << std::endl;

		std::cout << "bar contains:";
		for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << "\nbar contains:";
		for (it = --bar.end(); it!=bar.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize vector = " << bar.size() << std::endl;

		std::cout << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          CLEAR" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::vector<int> myvector;
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		std::cout << "\033[37m"<< std::endl;
		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "myvector contains: 100 200 300\nmyvector contains: 1101 2202"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];

		std::cout << "\nmyvector contains:";
		ft::vector<int>::iterator it;
		for (it = --myvector.end(); it!=myvector.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize vector = " << myvector.size() << std::endl;

		myvector.clear();
		myvector.push_back (1101);
		myvector.push_back (2202);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];

		std::cout << "\nmyvector contains:";
		for (it = --myvector.end(); it!=myvector.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize vector = " << myvector.size() << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          RELATIONAL OPERATOR" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int> bar (2,200);   // two ints with a value of 200

		std::cout << "\033[37m"<< std::endl;
		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "foo and bar are not equal\nfoo is less than bar\nfoo is less than or equal to bar"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          SWAP" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{

		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		std::cout << "\033[37m"<< std::endl;
		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "foo contains: 200 200 200 200 200\nbar contains: 100 100 100"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "foo contains:";
		for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << "\nfoo contains:";
		ft::vector<int>::iterator it;
		for (it = --foo.end(); it!=foo.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize vector = " << foo.size() << std::endl;

		std::cout << "bar contains:";
		for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << "\nbar contains:";
		for (it = --bar.end(); it!=bar.begin(); --it)
			std::cout << ' ' << *it;
		std::cout << ' ' << *it;
		std::cout << "\nsize vector = " << bar.size() << std::endl;

	}
    return 0;
}