/* Copyright 2017 R. Thomas
 * Copyright 2017 Quarkslab
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef LIEF_MACHO_SYMBOL_H_
#define LIEF_MACHO_SYMBOL_H_

#include <iostream>

#include "LIEF/types.hpp"
#include "LIEF/visibility.h"

#include "LIEF/Abstract/Symbol.hpp"

#include "LIEF/MachO/LoadCommand.hpp"


namespace LIEF {
namespace MachO {
class DLL_PUBLIC Symbol : public LIEF::Symbol {
  public:
    Symbol(void);

    Symbol(const nlist_32 *cmd);
    Symbol(const nlist_64 *cmd);

    Symbol& operator=(const Symbol& copy);
    Symbol(const Symbol& copy);
    virtual ~Symbol(void);

    uint8_t  type(void) const;
    uint8_t  numberof_sections(void) const;
    uint16_t description(void) const;
    uint64_t value(void) const;

    void type(uint8_t type);
    void numberof_sections(uint8_t nbsections);
    void description(uint16_t desc);
    void value(uint64_t);

    bool is_external(void) const;

    virtual void accept(Visitor& visitor) const override;

    bool operator==(const Symbol& rhs) const;
    bool operator!=(const Symbol& rhs) const;

    DLL_PUBLIC friend std::ostream& operator<<(std::ostream& os, const Symbol& symbol);

  private:
    uint8_t  type_;
    uint8_t  numberof_sections_;
    uint16_t description_;
    uint64_t value_;
};

}
}
#endif
