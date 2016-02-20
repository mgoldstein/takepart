function ad_call_check(ad_width) {
  if (ad_width === 728 && window.innerWidth < 768) {
    return false;
  }
  else if (ad_width === 320 && ((screen.width > 768))) {
    return false;
  }
  else {
    return true;
  }
}
