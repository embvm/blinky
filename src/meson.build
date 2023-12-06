# Blinky App Meson Build File

if get_option('enable-threading') == true

	blinky_simulator_app = executable('blinky_native',
		sources: ['blinky.cpp'],
		dependencies: [
			blinky_sim_platform_dep
		],
		native: true
	)

	# We want to build a demo app to test cross compilation on x86_64 with mainline clang
	if host_machine.cpu_family() == 'x86_64'
		blinky_simulator_app_x86 = executable('blinky_x86',
			sources: [
				'blinky.cpp',
			],
			dependencies: [
				blinky_sim_x86_platform_dep
			],
		)
	endif

endif

if host_machine.cpu_family() == 'arm'
	# TODO: convert to using the objcopy module!
	target_objcopy = find_program(meson.get_external_property('objcopy'))

	########################
	# NRF52 Dongle Targets #
	########################

	blinky_nrf52dongle_app = executable('blinky_dongle',
		sources: [
			'blinky.cpp',
		],
		c_args: [
		],
		cpp_args: [
		],
		link_args: [
			'-Wl,-Map=nrf52840_dongle_blinky.map',
		],
		dependencies: [
			blinky_nrf52dongle_platform_dep
		],
	)

	nrf52_dongle_blinky_hex = custom_target('blinky_dongle.hex',
		input: blinky_nrf52dongle_app,
		output: 'blinky_dongle.hex',
		command: [target_objcopy, '-O', 'ihex', '@INPUT@', '@OUTPUT@'],
		depends: blinky_nrf52dongle_app,
		build_by_default: true
	)

	nrf52_dongle_blinky_bin = custom_target('blinky_dongle.bin',
		input: blinky_nrf52dongle_app,
		output: 'blinky_dongle.bin',
		command: [target_objcopy, '-O', 'binary', '@INPUT@', '@OUTPUT@'],
		depends: blinky_nrf52dongle_app,
		build_by_default: true
	)

	#######################
	# NRF52840 DK Targets #
	#######################

	blinky_nrf52dk_app = executable('blinky_nrf52dk',
		sources: [
			'blinky.cpp',
		],
		c_args: [
			'-D__HEAP_SIZE=8192',
			'-D__STACK_SIZE=8192',
		],
		cpp_args: [
			'-D__HEAP_SIZE=8192',
			'-D__STACK_SIZE=8192',
		],
		link_args: [
			'-Wl,-Map=nrf52_dk_blinky.map',
		],
		dependencies: [
			framework_threadless_dep,
			blinky_nrf52dk_platform_dep
		],
	)

	nrf52dk_blinky_hex = custom_target('blinky_nrf52dk.hex',
		input: blinky_nrf52dk_app,
		output: 'blinky_nrf52dk.hex',
		command: [target_objcopy, '-O', 'ihex', '@INPUT@', '@OUTPUT@'],
		depends: blinky_nrf52dk_app,
		build_by_default: true
	)

	nrf52dk_blinky_bin = custom_target('blinky_nrf52dk.bin',
		input: blinky_nrf52dk_app,
		output: 'blinky_nrf52dk.bin',
		command: [target_objcopy, '-O', 'binary', '@INPUT@', '@OUTPUT@'],
		depends: blinky_nrf52dk_app,
		build_by_default: true
	)

# TODO: implement this example
'''
	blinky_fwdemo_nrf52dk_app = executable('blinky_fwdemo_nrf52dk',
		sources: [
			'blinky.cpp',
		],
		c_args: [
			'-D__HEAP_SIZE=8192',
			'-D__STACK_SIZE=8192',
		],
		cpp_args: [
			'-D__HEAP_SIZE=8192',
			'-D__STACK_SIZE=8192',
		],
		link_args: [
			'-Wl,-Map=nrf52dk_fwdemo_blinky.map',
		],
		dependencies: [
			framework_threadless_dep,
			fwdemo_nrf52dk_platform_dep
		],
	)

	nrf52dk_blinky_fwdemo_hex = custom_target('blinky_fwdemo_nrf52dk.hex',
		input: blinky_fwdemo_nrf52dk_app,
		output: 'blinky_fwdemo_nrf52dk.hex',
		command: [target_objcopy, '-O', 'ihex', '@INPUT@', '@OUTPUT@'],
		depends: blinky_fwdemo_nrf52dk_app,
		build_by_default: true
	)

	nrf52dk_blinky_fwdemo_bin = custom_target('blinky_fwdemo_nrf52dk.bin',
		input: blinky_fwdemo_nrf52dk_app,
		output: 'blinky_fwdemo_nrf52dk.bin',
		command: [target_objcopy, '-O', 'binary', '@INPUT@', '@OUTPUT@'],
		depends: blinky_fwdemo_nrf52dk_app,
		build_by_default: true
	)
'''
endif

clangtidy_files += files('blinky.cpp')
