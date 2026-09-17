#pragma once

// Keep Tracy completely out of the normal build.  This header is deliberately
// internal: it is included only by implementation files, never by the plugin's
// public GDExtension API.
#if defined(GODOT_SPOUT_ENABLE_TRACY)

#include <tracy/Tracy.hpp>

namespace spout_tracy {

inline void set_thread_name_once(const char *p_name) {
  thread_local bool named = false;
  if (!named) {
    tracy::SetThreadName(p_name);
    named = true;
  }
}

} // namespace spout_tracy

#define SPOUT_TRACY_ZONE(p_name) ZoneScopedN(p_name)
#define SPOUT_TRACY_TEXT(p_text, p_length) ZoneText(p_text, p_length)
#define SPOUT_TRACY_VALUE(p_value) ZoneValue(p_value)
#define SPOUT_TRACY_EVENT(p_name, p_counter) \
  TracyPlot(p_name, static_cast<int64_t>(++(p_counter)))
#define SPOUT_TRACY_THREAD_NAME(p_name) \
  spout_tracy::set_thread_name_once(p_name)

#else

#define SPOUT_TRACY_ZONE(p_name)
#define SPOUT_TRACY_TEXT(p_text, p_length)
#define SPOUT_TRACY_VALUE(p_value)
#define SPOUT_TRACY_EVENT(p_name, p_counter)
#define SPOUT_TRACY_THREAD_NAME(p_name)

#endif // GODOT_SPOUT_ENABLE_TRACY
