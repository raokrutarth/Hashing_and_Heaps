#ifndef __CCHASH_H__
#define __CCHASH_H__

class CCHash {
    private:
		int * T1;
		int * T2;
		int table_size;
		int h1(int x);
		int h2(int x);
		int maxLoops;
    
    public:
		CCHash(int initial_r, int ml);		
		void rehash();		
    	bool lookup(int x);
		bool insert(int x, int * tb1, int * tb2);
		bool remove(int x);
		void set_r(int nr);
		int * get_t1();
		int * get_t2();
};

#endif
