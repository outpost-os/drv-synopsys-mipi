# SPDX-FileCopyrightText: 2024 Ledger SAS
# SPDX-License-Identifier: Apache-2.0

project('synopsys-mipi', 'c',
    meson_version: '>=1.3.0',
    version: run_command('dunamai', 'from', 'git', '--style', 'semver', '--dirty', check: true).stdout().strip(),
    default_options: [
        'c_std=gnu11',
        'warning_level=3', 'optimization=s',
        'default_library=static', 'b_staticpic=false',
        'licensedir=share/info/libsynospys-mipi',
        'pkgconfig.relocatable=true',
        'config=configs/defconfig',
        'dts=dts/default.dts',
        'dts-include-dirs=dts',
])

pkg = import('pkgconfig')
ssmod = import('sourceset')

synopsys_mipi_deps = []
synospys_mipi_source_set = ssmod.source_set()
synopsys_mipi_inc = []
synopsys_mipi_compile_args = []

kconfig_file = meson.current_source_dir() / 'Kconfig'
kconfig_proj = subproject('kconfig', default_options: ['kconfig=@0@'.format(kconfig_file)])
kconfig_h = kconfig_proj.get_variable('kconfig_h')
kconfig_data = kconfig_proj.get_variable('kconfig_data')

devicetree_proj = subproject('devicetree')
dts = devicetree_proj.get_variable('devicetree_dtsd')
dts2src = devicetree_proj.get_variable('dts2src')
devicetree_dep = devicetree_proj.get_variable('devicetree_dep')

dtsgen = generator(dts2src,
    arguments: ['-d', dts.full_path() , '-t', '@INPUT@', '@OUTPUT@' ],
    depends: [ dts ],
    output: '@BASENAME@',
)

libshield_dep = dependency('shield')
synopsys_mipi_deps += [ libshield_dep ]

# XXX if configured
drv_ltdc_proj = subproject('drv-stm32-ltdc')
drv_ltdc_dep = drv_ltdc_proj.get_variable('libstm32_ltdc_dep')
synopsys_mipi_deps += [ drv_ltdc_dep ]

subdir('include')
subdir('src')

libsynospys_mipi_dep = declare_dependency(
    include_directories: synopsys_mipi_inc,
    link_with: synopsys_mipi_lib,
    dependencies: synopsys_mipi_deps,
    compile_args: synopsys_mipi_compile_args,
)

# TODO doc and test
