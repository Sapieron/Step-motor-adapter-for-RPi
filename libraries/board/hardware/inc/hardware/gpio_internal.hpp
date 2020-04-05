/**
 * @file gpio-internal.hpp
 * @author https://github.com/Sapieron
 * @brief  Provides helper functions to detect conflicts between pins,
 *         provides function to connect io_map to BOARDGpio
 * 
 * @version 0.1
 * @date 2020-03-14
 * 
 * @copyright Copyright (c) 2020
 */

#include "base/io_map.hpp"

namespace board
{
    namespace gpio
    {
        struct Conflicts
        {
            /** @brief Detect conflicts between pins */
            template <typename Left, typename Right>
            struct Conflict
            {
                static constexpr auto LeftPort = Left::PinLocation::Port;           //!< Left pin's port
                static constexpr auto LeftPinNumber = Left::PinLocation::PinNumber; //!< Left pin's number

                static constexpr auto RightPort = Right::PinLocation::Port;           //!< Right pin's port
                static constexpr auto RightPinNumber = Right::PinLocation::PinNumber; //!< Right pin's number

                /** @brief true if Left and Right points to the same pin */
                static constexpr bool value = (LeftPort == RightPort) && (LeftPinNumber == RightPinNumber);
            };

            /** @brief Entry point for conflict checking between two locations */
            template <typename Left, typename Right> static constexpr bool Is()
            {
                return Conflict<Left, Right>::value;
            }
        };

        template <template <typename...> class Base, typename... Pins>
        class VerifyPinsUniqueness final : public Base<Pins...>
        {
          private:
            /**
             * @brief Helper class to extract Pins template pack from flattened pins list
             */
            template <typename T>
            struct Helper;

            template <typename... Items>
            struct Helper<io_map::PinContainer<Items...>>
            {
            /**
            * @brief Checks if Pins are not overlapping
            * @return true if conflict detected
            */
            template <std::uint8_t Tag, typename Pin, typename... Rest> static constexpr bool ArePinsNotOverlapping()
            {
                if (HasConflictWith<Pin, Rest...>())
                    return false;

                return ArePinsNotOverlapping<0, Rest...>();
            }

            /**
             * @brief Empty list guard
             * @return Always true
             */
            template <std::uint8_t Tag> static constexpr bool ArePinsNotOverlapping()
            {
                return true;
            }

            /**
             * @brief Checks if Pin has conflict with any other pin location
             * @return true if conflict detected
            */
            template <typename Pin, typename Other, typename... Rest> static constexpr bool HasConflictWith()
            {
               if (Conflicts::template Is<Pin, Other>())
                   return true;

                return HasConflictWith<Pin, Rest...>();
            }

            /**
             * @brief Empty list guard
             * @return Always true
             */
            template <typename Pin> static constexpr bool HasConflictWith()
            {
                return false;
            }

            /** @brief Indicates that there is no conflict between pins */
            static constexpr bool HasNoConflict = ArePinsNotOverlapping<0, Items...>();
            };

        static_assert(Helper<typename io_map::Flatten<Pins...>::Result>::HasNoConflict, "Pins must not overlap");
        };
    } // namespace gpio
} // namespace board