#if !defined(PROTOCOL_HPP)
#define PROTOCOL_HPP

namespace PRTL
{
    const std::string USER = "usr";
    const std::string PASSWORD = "pwd";
    const std::string NB_ROOM = "nbroom";
    const std::string ID_ROOM = "id_room";

    enum class Actions {
        AUTH,
        JOIN_ROOM,
        GET_ROOMS,
        CREATE_ROOM,
        INFO_ROOM,
        NEWCO,
        UNKNOWN
    };

    enum class Responses {
        SUCCESS,
        FAILURE,
        UNKNOWN
    };
}; // namespace PRTL


#endif // PROTOCOL_HPP
