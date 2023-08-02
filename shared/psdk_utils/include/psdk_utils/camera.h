#ifndef PSDK_UTILS_CAMERA_H
#define PSDK_UTILS_CAMERA_H

#include <CCamera.h>
#include <CVector2D.h>

namespace psdk_utils {
inline CCamera& get_camera() { return TheCamera; }
inline CCam& get_active_cam() {
  return TheCamera.m_aCams[TheCamera.m_nActiveCam];
}

namespace camera {
CVector2D crosshair_offset();
bool is_player_aiming();
bool is_widescreen_fix_on();
}  // namespace camera
}  // namespace psdk_utils

#endif  // PSDK_UTILS_CAMERA_H
