#include <iostream>
#include "map.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};


int     main()
{
	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          CONSTRUCTEUR" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		ft::map<char,int> first;

		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;

		ft::map<char,int> second (first.begin(),first.end());

		ft::map<char,int> third (second);

		ft::map<char,int,classcomp> fourth;                 // class as Compare

		bool(*fn_pt)(char,char) = fncomp;
		ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

      
      	for (ft::map<char,int,bool(*)(char,char)>::iterator first = third.begin(); first != third.end(); ++first)
        	std::cout << first->first << std::endl;
	
		std::cout << "SIZE = " << third.size() << std::endl;


	}

  	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          OPERATOR=" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		ft::map<char,int> first;
		ft::map<char,int> second;

		first['x']=8;
		first['y']=16;
		first['z']=32;

		second = first;                // second now contains 3 ints
		first = ft::map<char,int>();  // and first is now empty

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "Size of first: 0\nSize of second: 3"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "Size of first: " << first.size() << '\n';
		std::cout << "Size of second: " << second.size() << '\n';

		for (ft::map<char, int>::iterator it = first.begin(); it != first.end(); ++it)
			std::cout << "first = " << it->first << std::endl;

		for (ft::map<char,int>::iterator first = second.begin(); first != second.end(); ++first)
			std::cout << "seconde = " << first->first << std::endl;
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          BEGIN" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
	  	ft::map<char,int> mymap;

		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "a => 200\nb => 100\nc => 300"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		// show content:
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << "mymap = " << it->first << std::endl;
		std::cout << "SIZE = " << mymap.size() << std::endl;
	}
	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          END" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		ft::map<char,int> mymap;

		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "a => 200\nb => 100\nc => 300"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		// show content:
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

		for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << "mymap = " << it->first << std::endl;
		std::cout << "SIZE = " << mymap.size() << std::endl;
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          RBEGIN" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		ft::map<char,int> mymap;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "z => 300\ny => 200\nx => 100"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		// show content:
		ft::map<char,int>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';

		for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << "mymap = " << it->first << std::endl;
		std::cout << "SIZE = " << mymap.size() << std::endl;
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          REND" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		ft::map<char,int> mymap;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "z => 300\ny => 200\nx => 100"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		// show content:
		ft::map<char,int>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			std::cout << rit->first << " => " << rit->second << '\n';

		for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << "mymap = " << it->first << std::endl;
		std::cout << "SIZE = " << mymap.size() << std::endl;
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          EMPTY" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		ft::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "a => 10\nb => 20\nc => 30"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		while (!mymap.empty())
		{
			std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
			mymap.erase(mymap.begin());
		}

		for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << "mymap = " << it->first << std::endl;
		std::cout << "SIZE = " << mymap.size() << std::endl;
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          SIZE" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		ft::map<char,int> mymap;
		mymap['a']=101;
		mymap['b']=202;
		mymap['c']=302;

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mymap.size() is 3"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "mymap.size() is " << mymap.size() << '\n';

		for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << "mymap = " << it->first << std::endl;
		std::cout << "SIZE = " << mymap.size() << std::endl;
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          MAZ_SIZE" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		int i;
		ft::map<int,int> mymap;

		if (mymap.max_size() > 1000)
		{
			for (i=0; i<1000; i++) mymap[i]=0;
			std::cout << "The map contains 1000 elements.\n";
		}
		else std::cout << "The map could not hold 1000 elements.\n";

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          OPERATOR[]" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		ft::map<char,std::string> mymap;
		mymap['a'] ="an element";
		mymap['b'] ="another element";
		mymap['c'] =mymap['b'];

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mymap['a'] is an element\nmymap['b'] is another element\nmymap['c'] is another element\nmymap['d'] is\nmymap now contains 4 elements."<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "mymap['a'] is " << mymap['a'] << '\n';
		std::cout << "mymap['b'] is " << mymap['b'] << '\n';
		std::cout << "mymap['c'] is " << mymap['c'] << '\n';
		std::cout << "mymap['d'] is " << mymap['d'] << '\n';

		std::cout << "mymap now contains " << mymap.size() << " elements.\n";

		for (ft::map<char, std::string>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << "mymap = " << it->first << std::endl;
		std::cout << "SIZE = " << mymap.size() << std::endl;
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          INSERT" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		ft::map<char,int> mymap;

		// first insert function version (single parameter):
		mymap.insert ( ft::pair<char,int>('a',100) );
		mymap.insert ( ft::pair<char,int>('z',200) );

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "element 'z' already existed with a value of 200\nmymap contains:\na => 100\nb => 300\nc => 400\nz => 200\nanothermap contains:\na => 100\nb => 300"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		ft::pair<ft::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( ft::pair<char,int>('z',500) );
		if (ret.second==false) {
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}

		// second insert function version (with hint position):
		ft::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
		mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

		// third insert function version (range insertion):
		ft::map<char,int> anothermap;
		std::cout << "find de c = " << mymap.find('c')->second << std::endl;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		// showing contents:
		std::cout << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << std::endl;
		std::cout << " MYMAP " << std::endl;
		std::cout << "SIZE = " << mymap.size() << std::endl;

		std::cout << std::endl;
		std::cout << " ANOTHERMAP " << std::endl;
		std::cout << "SIZE = " << anothermap.size() << std::endl;

	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          ERASE" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;

		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;

		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator

		mymap.erase ('c');                  // erasing by key

		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "a => 10\nd => 40"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		// show content:
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		for (it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << "mymap = " << it->first << std::endl;
		std::cout << "SIZE = " << mymap.size() << std::endl;
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          SWAP" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		
		ft::map<char,int> foo,bar;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

		foo.swap(bar);

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "foo contains:\na => 11\nb => 22\nc => 33\nbar contains:\nx => 100\ny => 200"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "foo contains:\n";
		for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "bar contains:\n";
		for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << std::endl;
		std::cout << "AFFICHAGE DE FOO" << std::endl;
		std::cout << "SIZE = " << foo.size() << std::endl;
		
		std::cout << std::endl;
		std::cout << "AFFICHAGE DE BAR" << std::endl;
		std::cout << "SIZE = " << bar.size() << std::endl;
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          CLEAR" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		
		ft::map<char,int> mymap;

		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mymap contains:\nx => 100\ny => 200\nz => 300\nmymap contains:\na => 1101\nb => 2202"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "mymap contains:\n";
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		mymap.clear();
		mymap['a']=1101;
		mymap['b']=2202;

		std::cout << "mymap contains:\n";
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << "SIZE = " << mymap.size() << std::endl;
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          KEY_COMP" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		ft::map<char,int> mymap;

		ft::map<char,int>::key_compare mycomp = mymap.key_comp();

		mymap['a']=100;
		mymap['b']=200;
		mymap['c']=300;

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mymap contains:\na => 100\nb => 200\nc => 300"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "mymap contains:\n";

		char highest = mymap.rbegin()->first;     // key value of last element

		ft::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mycomp((*it++).first, highest) );
		std::cout << "SIZE = " << mymap.size() << std::endl;
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          VALUE_COMP" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		ft::map<char,int> mymap;

		mymap['x']=1001;
		mymap['y']=2002;
		mymap['z']=3003;

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "mymap contains:\nx => 1001\ny => 2002\nz => 3003"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "mymap contains:\n";

		ft::pair<char,int> highest = *mymap.rbegin();          // last element

		ft::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );

		std::cout << "SIZE = " << mymap.size() << std::endl;
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          FIND" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;

		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;

		it = mymap.find('b');
		if (it != mymap.end())
			mymap.erase (it);

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "elements in mymap:\na => 50\nc => 150\nd => 200"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		// print content:
		std::cout << "elements in mymap:" << '\n';
		std::cout << "a => " << mymap.find('a')->second << '\n';
		std::cout << "c => " << mymap.find('c')->second << '\n';
		std::cout << "d => " << mymap.find('d')->second << '\n';

		std::cout << "SIZE = " << mymap.size() << std::endl;
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          COUNT" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		ft::map<char,int> mymap;
		char c;

		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "a is an element of mymap.\nb is not an element of mymap.\nc is an element of mymap.\nd is not an element of mymap.\ne is not an element of mymap.\nf is an element of mymap.\ng is not an element of mymap."<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		for (c='a'; c<'h'; c++)
		{
			std::cout << c;
			if (mymap.count(c)>0)
			std::cout << " is an element of mymap.\n";
			else 
			std::cout << " is not an element of mymap.\n";
		}

		std::cout << "SIZE = " << mymap.size() << std::endl;
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          LOWER_BOUND" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);        // erases [itlow,itup)

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "a => 20\ne => 100"<< std::endl;
		std::cout << "\033[37m"<< std::endl;		

		//print content:
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "SIZE = " << mymap.size() << std::endl;
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          UPPER_BOUND" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);        // erases [itlow,itup)

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "a => 20\ne => 100"<< std::endl;
		std::cout << "\033[37m"<< std::endl;

		// print content:
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "SIZE = " << mymap.size() << std::endl;
	}

	std::cout << "\n\033[1;33m======================================================" << std::endl;
	std::cout << "          EQUAL_RANGE" << std::endl;
	std::cout << "======================================================\033[37m\n" << std::endl;
	{
		ft::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');

		std::cout << "\033[1;31mreponse attendu:\033[1;32m"<< std::endl;
		std::cout << "lower bound points to: 'b' => 20\nupper bound points to: 'c' => 30" << std::endl;
		std::cout << "\033[37m"<< std::endl;

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';

		std::cout << "SIZE = " << mymap.size() << std::endl;
	}
}