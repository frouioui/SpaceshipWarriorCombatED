#if !defined(PROTOCOL_HPP)
#define PROTOCOL_HPP

namespace PRTL
{
    enum class Data {
        ACTION,
        RESPONSE,
        TOKEN,
        USER,
        PASSWORD,
        NB_ROOM,
        ID_ROOM,
        CONTENT,
        CIRCLE,
        CIRCLE_POS_CENTER_Y,
        CIRCLE_POS_CENTER_X,
        CIRCLE_POS_RADIUS,
        SQUARE,
        SQUARE_UPPERLEFT_Y,
        SQUARE_UPPERLEFT_X,
        SQUARE_UPPERRIGHT_Y,
        SQUARE_UPPERRIGHT_X,
        SQUARE_LOWERLEFT_Y,
        SQUARE_LOWERLEFT_X,
        SQUARE_LOWERRIGHT_Y,
        SQUARE_LOWERRIGHT_X,
        INPUT
    };

    enum class Actions {
        AUTH,
        JOIN_ROOM,
        GET_ROOMS,
        CREATE_ROOM,
        INFO_ROOM,
        READY,
        BOUNDINGBOX,
        INPUT,
        NEWCO,
        GOODBYE,
        UNKNOWN
    };

    enum class Responses {
        SUCCESS,
        FAILURE,
        UNKNOWN
    };
}; // namespace PRTL


#endif // PROTOCOL_HPP
