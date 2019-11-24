#if !defined(PROTOCOL_HPP)
#define PROTOCOL_HPP

namespace PRTL
{
    const std::string USER = "usr";
    const std::string PASSWORD = "pwd";

    enum class Actions {
        AUTH,
        PING,
        UNKNOWN
    };

    enum class Responses {
        SUCCESS,
        FAILURE,
        PING,
        UNKNOWN
    };
}; // namespace PRTL


#endif // PROTOCOL_HPP
