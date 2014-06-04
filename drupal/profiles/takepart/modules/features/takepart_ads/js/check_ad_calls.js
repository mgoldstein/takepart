function ad_call_check(ad_width) {
    if (ad_width === 728 && window.innerWidth < 768) {
        return false;
    }
    else if (ad_width === 1 && window.innerWidth < 768) {
        return false;
    }
    else if (ad_width === 320 && ((window.innerWidth > 768) || (jQuery.cookie("close_mobile_ad") != null))) {
        return false;
    }
    else {
        return true;
    }
}