#pragma once

namespace sahifa
{
	#define SWITCH_CASE_ENUM_STRING(e)  case e:  { return #e; }
	#define SWITCH_CASE_DEFAULT_CRASH() default: { abort(); }

} // namespace sahifa