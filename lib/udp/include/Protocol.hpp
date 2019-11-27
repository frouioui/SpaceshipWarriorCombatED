#if !defined(PROTOCOL_HPP)
#define PROTOCOL_HPP

namespace PRTL
{
    const std::string USER = "usr";
    const std::string PASSWORD = "pwd";
    const std::string NB_ROOM = "nbroom";
    const std::string ID_ROOM = "id_room";
    const std::string CONTENT = "content";

    const std::string CIRCLE = "circle";
    const std::string CIRCLE_POS_CENTER_Y = "circle_center_y";
    const std::string CIRCLE_POS_CENTER_X = "circle_center_x";
    const std::string CIRCLE_POS_RADIUS = "circle_radius";

    const std::string SQUARE = "square";
    const std::string SQUARE_UPPERLEFT_Y = "square_upperleft_y";
    const std::string SQUARE_UPPERLEFT_X = "square_upperleft_x";
    const std::string SQUARE_UPPERRIGHT_Y = "square_upperight_y";
    const std::string SQUARE_UPPERRIGHT_X = "square_upperight_x";
    const std::string SQUARE_LOWERLEFT_Y = "square_lowerleft_y";
    const std::string SQUARE_LOWERLEFT_X = "square_lowerleft_x";
    const std::string SQUARE_LOWERRIGHT_Y = "square_lowerright_y";
    const std::string SQUARE_LOWERRIGHT_X = "square_lowerright_x";

    const std::string INPUT = "input";

    enum class Actions {
        AUTH,
        JOIN_ROOM,
        GET_ROOMS,
        CREATE_ROOM,
        INFO_ROOM,
        BOUNDINGBOX,
        INPUT,
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
