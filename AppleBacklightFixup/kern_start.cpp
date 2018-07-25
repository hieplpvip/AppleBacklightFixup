//
//  kern_start.cpp
//  AppleBacklightFixup
//
//  Copyright © 2018 hieplpvip. All rights reserved.
//

#include <Headers/plugin_start.hpp>
#include <Headers/kern_api.hpp>

#include "kern_applbkl.hpp"

static APPLBKL applbkl;

static const char *bootargOff[] {
	"-applbkloff"
};

static const char *bootargDebug[] {
	"-applbkldbg"
};

static const char *bootargBeta[] {
	"-applbklbeta"
};

PluginConfiguration ADDPR(config) {
	xStringify(PRODUCT_NAME),
    parseModuleVersion(xStringify(MODULE_VERSION)),
    LiluAPI::AllowNormal | LiluAPI::AllowInstallerRecovery | LiluAPI::AllowSafeMode,
	bootargOff,
	arrsize(bootargOff),
	bootargDebug,
	arrsize(bootargDebug),
	bootargBeta,
	arrsize(bootargBeta),
	KernelVersion::Sierra,
	KernelVersion::Mojave,
	[]() {
		applbkl.init();
	}
};
