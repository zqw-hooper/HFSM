#pragma once

#if defined HFSM_ENABLE_LOG_INTERFACE || defined HFSM_ENABLE_STRUCTURE_REPORT

////////////////////////////////////////////////////////////////////////////////

namespace hfsm {

enum class Method : ShortIndex {
	GUARD,
	ENTER,
	UPDATE,
	REACT,
	EXIT,

	COUNT
};

enum class Transition : ShortIndex {
	RESTART,
	RESUME,
	SCHEDULE,

	COUNT
};

//------------------------------------------------------------------------------

static inline
const char*
stateName(const std::type_index stateType) {
	const char* const raw = stateType.name();

	#if defined(_MSC_VER)

		auto first =
			raw[0] == 's' ? 7 : // Struct
			raw[0] == 'c' ? 6 : // Class
							0;
		return raw + first;

	#elif defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)

		return raw;

	#else

		return raw;

	#endif
}

//------------------------------------------------------------------------------

static inline
const char*
methodName(const ::hfsm::Method method) {
	switch (method) {
		case Method::GUARD:		return "guard";
		case Method::ENTER:		return "enter";
		case Method::UPDATE:	return "update";
		case Method::REACT:		return "react";
		case Method::EXIT:		return "exit";

		default:
			HSFM_BREAK();
			return nullptr;
	}
}

//------------------------------------------------------------------------------

static inline
const char*
transitionName(const ::hfsm::Transition transition) {
	switch (transition) {
		case Transition::RESTART:		return "changeTo";
		case Transition::RESUME:		return "resume";
		case Transition::SCHEDULE:		return "schedule";

		default:
			HSFM_BREAK();
			return nullptr;
	}
}

////////////////////////////////////////////////////////////////////////////////

}

#endif
