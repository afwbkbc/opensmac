#include <algorithm>

#include "SimpleScheduler.h"

namespace scheduler {

SimpleScheduler::SimpleScheduler() {

}

void SimpleScheduler::Start() {
	m_active = true;
	for ( auto it = m_tasks.begin() ; it < m_tasks.end() ; it++ ) {
		Log( "Starting task [" + (*it)->GetName() + "]" );
		(*it)->Start();
	}
}

void SimpleScheduler::Stop() {
	for ( auto it = m_tasks.begin() ; it < m_tasks.end() ; it++ ) {
		Log( "Stopping task [" + (*it)->GetName() + "]" );
		(*it)->Stop();
	}
	m_active = false;
}

void SimpleScheduler::Iterate() {
	for ( auto it = m_tasks.begin() ; it < m_tasks.end() ; it++ )
		(*it)->Iterate();
}

void SimpleScheduler::AddTask( task::Task *task ) {
	m_tasks.push_back( task );
	if ( m_active ) {
		Log( "Starting task [" + task->GetName() + "]" );
		task->Start();
	}
}

void SimpleScheduler::RemoveTask( task::Task *task ) {
	auto it = std::find( m_tasks.begin(), m_tasks.end(), task );
	if ( it == m_tasks.end() )
		throw SchedulerError( "removal of non-existent task" );
	if ( m_active ) {
		Log( "Stopping task [" + task->GetName() + "]" );
		task->Stop();
	}
	m_tasks.erase( it, it + 1 );
}

} /* namespace scheduler */
