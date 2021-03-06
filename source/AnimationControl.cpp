/** \file AnimationControl.cpp */
#include "AnimationControl.h"

AnimationControl::AnimationControl() {
	m_currentTime = 0.0f;
}


AnimationControl::AnimationControl( std::function<void(SimTime, SimTime, shared_ptr<Table<String, float>>, Table< Point3int32, shared_ptr<VisibleEntity>>&, Table< Point3int32, SimTime>& )> c) {

	m_currentTime = 0.0f;
	m_callback = c;

	args = std::make_shared<Table<String,float>>(Table<String,float>());

}

void AnimationControl::invoke(SimTime sdt) {
	m_currentTime += sdt;
	m_callback(sdt, m_currentTime, args, activeVoxels, timeAdded);
}