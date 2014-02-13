<form id="sys-form" class="sys-form" action="/">
  <fieldset>
    <legend>About You</legend>
    <div class="field-wrapper left"><label for="first_name">First Name</label><input type="text" name="first_name" id="first_name" placeholder="First Name*" required></div>
    <div class="field-wrapper right"><label for="last_name">Last Name</label><input type="text" name="last_name" id="last_name" placeholder="Last Name*" required></div>
    <div class="field-wrapper"><label for="email">Email</label><input type="email" name="email" id="email" placeholder="Email*" required></div>
    <div>COPPA stuff TBD</div>
  </fieldset>
  <fieldset>
    <legend>Your Teacher</legend>
    <div class="field-wrapper left"><label for="teacher_first_name">First Name</label><input type="text" name="teacher_first_name" id="teacher_first_name" placeholder="First Name*" required></div>
    <div class="field-wrapper right"><label for="teacher_last_name">Last Name</label><input type="text" name="teacher_last_name" id="teacher_last_name" placeholder="Last Name*" required></div>
    <div>School Selection TBD</div>
  </fieldset>
  <fieldset>
    <legend>Your Story</legend>
    <div class="field-wrapper"><label for="story_title">Story Title</label><input type="text" name="story_title" id="story_title" placeholder="Story Title*" maxlength="100" required></div>
    <div class="field-wrapper field-wrapper-story-year clearfix"><label class="visible"><span class="vertically-center">Approximate Year This Story Happened</span><input type="text" maxlength="4" id="story_year" name="story_year" class="story-year pull-right" required></label></div>
    <div class="field-wrapper"><label for="story_body">Your Story</label><textarea name="story_body" id="story_body" cols="30" rows="10" placeholder="Tell us your story" maxlength="400" required></textarea></div>
  </fieldset>
  <fieldset>
    <legend>Pictures Make The Story</legend>
    <input type="hidden" name="image_link">
    <input type="hidden" name="teacher_image_link">
    <div id="sys-image-user" class="sys-image sys-image-user left">
      USER IMAGE
    </div>
    <div id="sys-image-teacher" class="sys-image sys-image-teacher right">
      TEACHER IMAGE
    </div>
  </fieldset>
  <fieldset>
    <div class="field-wrapper clearfix"><input type="checkbox" class="pull-left" id="email_subscribe" name="email_subscribe"><label for="email_subscribe" class="visible">I would like to receive TakePart's newsletter on topics related to teaching and education</label></div>
    <div class="field-wrapper field-wrapper-terms-agree"><input type="checkbox" id="terms_agree" name="terms_agree" required><label for="terms_agree" class="visible">I have read and agree to the <a href="#">content submission agreement</a></label></div>
  </fieldset>
  <p class="clearfix">
    <a href="#" id="sys-preview" class="sys-button left">Preview Story</a>
    <a href="#" id="sys-submit" class="sys-button sys-button-submit right">Submit Story</a>
  </p>
  <p class="fine-print clearfix">By clicking "Submit Story" above, you agree to TakePart's <?php print l('Terms of Use', 'terms-of-use', array('attributes' => array('target' => '_blank'))); ?> and <?php print l('Privacy Policy', 'privacy-policy', array('attributes' => array('target' => '_blank'))); ?></p>
</form>
