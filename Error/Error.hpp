/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** Error classes
*/

#ifndef ERROR_HPP_
    #define ERROR_HPP_

#include <exception>
#include <iostream>

namespace Error {
    class Error: public std::exception
    {
        public:
            Error(const std::string &message, const std::string &where = "Unknown");
            virtual ~Error() throw() {};

            const std::string &where() const;
            const char* what() const noexcept override;

        protected:
            std::string _where;
        private:
            std::string _message;
    };

    namespace Sfml {
        class AssetError: public Error
        {
            public:
                AssetError(std::string const &message, std::string const &where = "Unknown") : Error(message, where) {};
                virtual ~AssetError() throw() {};
        };

        class SfmlError : public Error
        {
            public:
                SfmlError(std::string const &message, std::string const &where = "Unknown") : Error(message, where) {};
                virtual ~SfmlError() throw() {};
        };
    }
}

#endif /* !ERROR_HPP_ */
