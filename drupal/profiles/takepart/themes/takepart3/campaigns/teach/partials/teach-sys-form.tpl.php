<form id="sys-form" class="sys-form" action="/">
  <fieldset>
    <legend>About You</legend>
    <div class="field-wrapper"><label for="first_name">First Name</label><input type="text" name="first_name" id="first_name" placeholder="First Name*"></div>
    <div class="field-wrapper"><label for="last_name">Last Name</label><input type="text" name="last_name" id="last_name" placeholder="Last Name*"></div>
    <div class="field-wrapper"><label for="email">Email</label><input type="email" name="email" id="email" placeholder="Email*"></div>
    <div>COPPA stuff TBD</div>
  </fieldset>
  <fieldset>
    <legend>Your Teacher</legend>
    <div class="field-wrapper"><label for="teacher_first_name">First Name</label><input type="text" name="teacher_first_name" id="teacher_first_name" placeholder="First Name*"></div>
    <div class="field-wrapper"><label for="teacher_last_name">Last Name</label><input type="text" name="teacher_last_name" id="teacher_last_name" placeholder="Last Name*"></div>
    <div>School Selection TBD</div>
  </fieldset>
  <fieldset>
    <legend>Your Story</legend>
    <div class="field-wrapper"><label for="story_title">Story Title</label><input type="text" name="story_title" id="story_title" placeholder="Story Title*" maxlength="100"><p class="character-count"><span></span> Characters Left</p></div>
    <div class="field=wrapper"><label class="visible">Approximate Year This Story Happened<select id="story_year" name="story_year" class="pull-right"></select></label></div>
    <div class="field-wrapper"><label for="story_body">Your Story</label><textarea name="story_body" id="story_body" cols="30" rows="10" placeholder="Tell us your story" maxlength="400"></textarea><p class="character-count character-count-story-body"><span></span> Characters Left</p></div>
  </fieldset>
  <fieldset>
    <legend>Pictures Make The Story</legend>
    <input type="hidden" name="image_link">
    <input type="hidden" name="teacher_image_link">
    <div id="sys-image-user" class="sys-image sys-image-user">
      USER IMAGE
    </div>
    <div id="sys-image-teacher" class="sys-image sys-image-teacher">
      TEACHER IMAGE
    </div>
  </fieldset>
  <fieldset>
    <label class="visible clearfix"><input type="checkbox" class="pull-left" name="email_subscribe">I would like to receive TakePart's newsletter on topics related to teaching and education</label>
    <label class="visible"><input type="checkbox" name="terms_agree">I have read and agree to the <a href="#">content submission agreement</a></label>
  </fieldset>
  <p class="clearfix">
    <a href="#" id="sys-preview" class="sys-button">Preview Story</a>
    <a href="#" id="sys-submit" class="sys-button sys-button-submit">Submit Story</a>
  </p>
  <p class="fine-print clearfix">By clicking "Submit Story" above, you agree to TakePart's <?php print l('Terms of Use', 'terms-of-use', array('attributes' => array('target' => '_blank'))); ?> and <?php print l('Privacy Policy', 'privacy-policy', array('attributes' => array('target' => '_blank'))); ?></p>
</form>
