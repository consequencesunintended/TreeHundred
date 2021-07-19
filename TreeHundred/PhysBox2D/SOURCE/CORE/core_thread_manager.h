#pragma once


#include "fundamental_singleton.h"
#include "core_thread_pool.h"
#include <functional>

class CORE_THREAD_MANAGER : public FUNDAMENTAL_SINGLETON< CORE_THREAD_MANAGER >
{
public:

	void add_job( std::function<void()> f )
	{
		thread_pool.add_job( f );
	}

	void run( void )
	{
		thread_pool.run();
	}

	int get_num_avaialable_threads( void )
	{
#ifndef DISABLE_THREADING
		return thread_pool.get_num_avaialable_threads();
#else
		return 1;
#endif
	}

private:

	CORE_THREAD_POOL thread_pool;
};