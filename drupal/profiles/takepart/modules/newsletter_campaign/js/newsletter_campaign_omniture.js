function newsletter_campaign_track_signup(title) {
  s.linkTrackVars="eVar23,events";
  s.linkTrackEvents="event39";
  s.eVar23=title;
  s.events='event39';
  s.tl(true, 'o', 'Newsletter Signup');

  s.linkTrackVars="eVar28,events";
  s.linkTrackEvents="event19";
  s.eVar28='Newsletter Signup';
  s.events='event19';
  s.tl(true, 'o', 'Action Click');
}
