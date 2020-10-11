/**
 * @file io_map.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief  This file defines templates for specific I/O used within the board
 * @version 0.1
 * @date 2020-03-14
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */

#ifndef LIBS_TEMPLATE_INCLUDE_BASE_IO_MAP_H_
#define LIBS_TEMPLATE_INCLUDE_BASE_IO_MAP_H_

#pragma once

#include <cstdint>

namespace io_map
{
    /**
     * @defgroup io_map_base I/O Map support utilities
     * @{
     */

    /**
     * @brief Tag for type describing pin location
     *
     * Derived type must provide following static members:
     *  - Port address of type uint32_t
     *  - PinNumber of type std::uint16_t
     */
    struct PinTag
    {
    };

    /**
     * @brief Type describing pin location
     * @tparam TPort GPIO port
     * @tparam TPinNumber Pin number
     */
    template <std::uint32_t TPort, std::uint16_t TPinNumber = 0>
    struct PinLocation : public PinTag
    {
        /** @brief Selected port */
        static constexpr auto Port      = TPort;
        /** @brief Selected pin number */
        static constexpr auto PinNumber = TPinNumber;
    };

    /** @brief Packs many pins into single type */
    template <typename... T> struct PinContainer final
    {
    };

    /**
     * @brief Tag for type describing few pins grouped together (like peripheral pins)
     *
     * Derived type must provider inner type Group with typedef leading to @ref PinContainer
     */
    struct PinGroupTag
    {
    };

    /**
     * @brief Base type for describing UART pins location
     */
    template<typename Self>
    struct UARTPins : public PinGroupTag
    {
        struct Group
        {
            /** @brief UART Pins container */
            using Pins = PinContainer< typename Self::RX, typename Self::TX >;
        };
    };

    /**
     * @brief Base type for describing stepper motor pins location
     * @tparam Self - typename of pins
     */
    template <typename Self>
    struct MotorPins : public PinGroupTag
    {
        struct Group
        {

            using Pins = PinContainer<  typename Self::Dir,
                                        typename Self::Ms1,
                                        typename Self::Ms2,
                                        typename Self::Ms3,
                                        typename Self::Step>;
        };
    };

    /**
     * @brief Base type for describing water sensor pin location
     * 
     * @tparam Self - typename of pin
     */
    template <typename Self>
    struct DigitalSensorPins : public PinGroupTag
    {
        struct Group
        {
            /** @brief DigitalSensorPins container */
            using Pins = PinContainer<typename Self::SIG>;
        };
    };


    /**
     * @brief Group of pins on the same port
     */
    template <std::uint32_t Port, std::uint32_t... PinNumbers>
    struct PortPins : public PinGroupTag
    {
        /** @brief Port pins group */
        struct Group
        {
            /** @brief Port pins group */
            using Pins = PinContainer<PinLocation<Port, PinNumbers>...>;
        };
    };

    /** @brief Helper class for flattening pin list */
    template <typename Acc, typename... Items>
    struct FlattenHelper;

    /** @brief Class that converts PinGroup into @ref io_map::PinContainer*/
    template <typename... Accs, typename Group, typename... Rest>
    struct FlattenHelper<io_map::PinContainer<Accs...>, Group, Rest...>
    {
        /** @brief @ref io_map::PinContainer with inner pins */
        using Inner = typename Group::Group::Pins;

        /** @brief Result */
        using Result = typename FlattenHelper<io_map::PinContainer<Accs...>, Inner, Rest...>::Result;
    };

    /** @brief Class that flattens @ref io_map::PinContainer */
    template <typename... Accs, typename... Pins, typename... Rest>
    struct FlattenHelper<io_map::PinContainer<Accs...>, io_map::PinContainer<Pins...>, Rest...>
    {
        /** @brief Result */
        using Result = typename FlattenHelper<io_map::PinContainer<Accs...>, Pins..., Rest...>::Result;
    };

    /** @brief Class that adds single @ref io_map::PinLocation into result accumulator */
    template <typename... Acc, std::uint32_t Port, std::uint16_t Pin, typename... Rest>
    struct FlattenHelper<io_map::PinContainer<Acc...>, io_map::PinLocation<Port, Pin>, Rest...>
    {
        /** @brief Result */
        using Result = typename FlattenHelper<io_map::PinContainer<Acc..., io_map::PinLocation<Port, Pin>>, Rest...>::Result;
    };

    /** @brief Empty list guard */
    template <typename... Accs>
    struct FlattenHelper<io_map::PinContainer<Accs...>>
    {
        /** @brief Final @ref io_map::PinContainer */
        using Result = io_map::PinContainer<Accs...>;
    };

    /** @brief Class that flattens pin list given as template parameter pack */
    template <typename... Pins>
    struct Flatten
    {
        /** @brief Type of @ref io_map::PinContainer with flattened pin locations */
        using Result = typename FlattenHelper<io_map::PinContainer<>, Pins...>::Result;
    };
    /** @} */
}

#endif /* LIBS_TEMPLATE_INCLUDE_BASE_IO_MAP_H_ */
