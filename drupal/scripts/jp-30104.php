<?php

// Enable the module
module_enable(array('bluestatedigital'));
module_enable(array('bluestatedigital_user'));
module_enable(array('bluestatedigital_forms'));

// Rebuild the menu router
menu_rebuild();
