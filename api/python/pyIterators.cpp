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
#include "pyLIEF.hpp"
#include "pyIterators.hpp"

#include "LIEF/PE/signature/types.hpp"

void init_LIEF_iterators(py::module& m) {
  // Abstract
  // ========
  init_ref_iterator<LIEF::it_sections>(m);
  init_ref_iterator<LIEF::it_symbols>(m);

  // ELF
  // ===
#if defined(LIEF_ELF_MODULE)
  init_ref_iterator<LIEF::ELF::it_sections>(m);
  init_ref_iterator<LIEF::ELF::it_segments>(m);
  init_ref_iterator<LIEF::ELF::it_dynamic_entries>(m);
  init_ref_iterator<LIEF::ELF::it_symbols>(m);
  init_ref_iterator<LIEF::ELF::it_relocations>(m);
  init_ref_iterator<LIEF::ELF::it_symbols_version>(m);
  init_ref_iterator<LIEF::ELF::it_symbols_version_requirement>(m);
  init_ref_iterator<LIEF::ELF::it_symbols_version_definition>(m);
  init_ref_iterator<LIEF::filter_iterator<LIEF::ELF::symbols_t>>(m);
  init_ref_iterator<LIEF::ELF::it_symbols_version_aux>(m);
  init_ref_iterator<LIEF::ELF::it_symbols_version_aux_requirement>(m);
#endif

  // PE
  // ==
#if defined(LIEF_PE_MODULE)
  init_ref_iterator<LIEF::PE::it_sections>(m);
  init_ref_iterator<LIEF::PE::it_data_directories>(m);
  init_ref_iterator<LIEF::PE::it_relocations>(m);
  init_ref_iterator<LIEF::PE::it_imports>(m);
  init_ref_iterator<LIEF::PE::it_import_entries>(m);
  init_ref_iterator<LIEF::PE::it_export_entries>(m);
  init_ref_iterator<LIEF::PE::it_symbols>(m);
  init_ref_iterator<LIEF::PE::it_const_crt>(m);
#endif


  // MachO
  // =====
#if defined(LIEF_MACHO_MODULE)
  init_ref_iterator<LIEF::MachO::it_commands>(m);
  init_ref_iterator<LIEF::MachO::it_symbols>(m);
  init_ref_iterator<LIEF::filter_iterator<LIEF::MachO::symbols_t>>(m);
  init_ref_iterator<LIEF::MachO::it_libraries>(m);
  init_ref_iterator<LIEF::MachO::it_segments>(m);
  init_ref_iterator<LIEF::MachO::it_sections>(m);
#endif

}
