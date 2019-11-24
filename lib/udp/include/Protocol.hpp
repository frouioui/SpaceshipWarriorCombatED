#if !defined(PROTOCOL_HPP)
#define PROTOCOL_HPP

namespace PRTL
{
    const std::string USER = "usr";
    const std::string PASSWORD = "pwd";

    enum class Actions {
        AUTH,
        UNKNOWN
    };

    enum class Responses {
        SUCCESS,
        FAILURE,
        UNKNOWN
    };
}; // namespace PRTL


#endif // PROTOCOL_HPP
