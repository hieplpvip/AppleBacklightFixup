//
//  kern_applbkl.hpp
//  AppleBacklightFixup
//
//  Copyright © 2018 hieplpvip. All rights reserved.
//

#ifndef kern_applbkl_hpp
#define kern_applbkl_hpp

#include <Headers/kern_patcher.hpp>

class APPLBKL {
public:
	bool init();
	void deinit();
	
private:
	/**
	 *  Patch kext if needed and prepare other patches
	 *
	 *  @param patcher KernelPatcher instance
	 *  @param index   kinfo handle
	 *  @param address kinfo load address
	 *  @param size    kinfo memory size
	 */
    void processKext(KernelPatcher &patcher, size_t index, mach_vm_address_t address, size_t size);
    
    /**
     *  Current progress mask
     */
    struct ProcessingState {
        enum {
            NothingReady = 0,
            AppleBacklightPatched = 2,
            EverythingDone = AppleBacklightPatched,
        };
    };
    int progressState {ProcessingState::NothingReady};
};

#endif /* kern_applbkl */
