# SPDX-FileCopyrightText: 2024 Ledger SAS
# SPDX-License-Identifier: Apache-2.0

synospys_mipi_source_set.add(files(
    'mipi_dsi.c',
    'mipi_dsi_host.c',
))

mipi_dsi_dt_c_in = files(['mipi_dsi_dt.c.in'])
mipi_dsi_dt_c = dtsgen.process(
    mipi_dsi_dt_c_in,
    env: [ 'CONFIG_TASK_LABEL='+kconfig_data.get('CONFIG_TASK_LABEL', '0') ],
)
synospys_mipi_source_set.add(mipi_dsi_dt_c)

synospys_mipi_sources = synospys_mipi_source_set.apply(kconfig_data, strict: false)

synopsys_mipi_lib = static_library(
    meson.project_name(),
    sources : [ synospys_mipi_sources.sources() ],
    c_args : [ synopsys_mipi_compile_args ],
    include_directories: [ synopsys_mipi_inc ],
    dependencies: [ synopsys_mipi_deps ],
    install: true,
)
