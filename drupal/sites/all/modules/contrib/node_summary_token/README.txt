
Makes sure that the [node:summary] token (as used in <a href="http://drupal.org/project/metatag">metatag module</a> as the default description <em>actually works</em> in D7.

This is a <em>work-around</em> mini-module that addresses the long-standing problem <a href="http://drupal.org/node/1295524">identified in Sept 2011 as "[node:summary] does not work in default content meta tag when summary left empty"</a> and eventually branched as <a href="http://drupal.org/node/1300920">a core patch in "The [node:summary] token does not output anything for body fields without a manual summary"</a> - which got bumped to Drupal 8 (no backport yet) and at October 10, 2012, is still not in.

The code here is based on a <a href="http://drupal.org/node/1295524#comment-5825254">stand-alone module example</a> from <a href="http://drupal.org/user/960720">Marty2081 on April 18, 2012</a> (and the code that is pending inclusion in D8) but I reworked it to use <a href="http://api.drupal.org/api/drupal/modules%21system%21system.api.php/function/hook_tokens_alter/7">hook_tokens_alter</a> so that it could <em>override</em> the core [node:summary] token transparently instead of using a new made-up replacement token.

ONLY use this module if you are using metatag and want the "description" to use your nodes body teaser text (which is the expected default) and you've found that it's not working.

<h3>Alternative</h3>
This task can also be done with a <b>core hack</b> that anticipates the eventual core patch that should have gone in a while ago.
For convenience, a D7 copy of this hack/patch is also included in this module distribution. Use <em>one or the other, not both</em> fixes. The patch file here is a straight backport of the patch pending (slowly) in <a href="http://drupal.org/node/1300920#comment-6582536">the core D8 queue</a>


