/* Copyright 2018 dek <dek@yolops.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef ATREIS_H
#define ATREIS_H

#include "quantum.h"

#define LAYOUT( \
    k00, k01, k02, k03, k04, k05,             k06, k07, k08, k09, k10, k11,\
    k12, k13, k14, k15, k16, k17,             k18, k19, k20, k21, k22, k23,\
    k24, k25, k26, k27, k28, k29,             k30, k31, k32, k33, k34, k35,\
    k36, k37, k38, k39, k40, k41, k51,   k52, k42, k43, k44, k45, k46, k47,\
                     k48, k49, k50,         k53, k54, k55\
) \
{ \
    { k00, k01, k02, k03, k04, k05, k51 },\
    { k12, k13, k14, k15, k16, k17, k50 },\
    { k24, k25, k26, k27, k28, k29, k49 },\
    { k36, k37, k38, k39, k40, k41, k48 },\
    { k11, k10, k09, k08, k07, k06, k52 },\
    { k23, k22, k21, k20, k19, k18, k53 },\
    { k35, k34, k33, k32, k31, k30, k54 },\
    { k47, k46, k45, k44, k43, k42, k55 } \
}

// Used to create a keymap using only KC_ prefixed keys
#define LAYOUT_kc( \
    k00, k01, k02, k03, k04, k05,             k06, k07, k08, k09, k10, k11,\
    k12, k13, k14, k15, k16, k17,             k18, k19, k20, k21, k22, k23,\
    k24, k25, k26, k27, k28, k29,             k30, k31, k32, k33, k34, k35,\
    k36, k37, k38, k39, k40, k41, k51,   k52, k42, k43, k44, k45, k46, k47,\
                     k48, k49, k50,         k53, k54, k55\
) \
LAYOUT( \
    KC_##k00, KC_##k01, KC_##k02, KC_##k03, KC_##k04, KC_##k05,             KC_##k06, KC_##k07, KC_##k08, KC_##k09, KC_##k10, KC_##k11,\
    KC_##k12, KC_##k13, KC_##k14, KC_##k15, KC_##k16, KC_##k17,             KC_##k18, KC_##k19, KC_##k20, KC_##k21, KC_##k22, KC_##k23,\
    KC_##k24, KC_##k25, KC_##k26, KC_##k27, KC_##k28, KC_##k29,             KC_##k30, KC_##k31, KC_##k32, KC_##k33, KC_##k34, KC_##k35,\
    KC_##k36, KC_##k37, KC_##k38, KC_##k39, KC_##k40, KC_##k41, KC_##k51,   KC_##k52, KC_##k42, KC_##k43, KC_##k44, KC_##k45, KC_##k46, KC_##k47,\
                     KC_##k48, KC_##k49, KC_##k50,         KC_##k53, KC_##k54, KC_##k55\
) \

#endif
