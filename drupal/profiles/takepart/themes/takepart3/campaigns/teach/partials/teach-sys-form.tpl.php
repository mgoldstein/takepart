<form id="sys-form" class="sys-form" action="/">
  <fieldset>
    <legend>About You</legend>
    <div class="field-wrapper left"><label for="first_name">First Name</label><input type="text" name="first_name" id="first_name" placeholder="First Name*" required></div>
    <div class="field-wrapper right"><label for="last_name">Last Name</label><input type="text" name="last_name" id="last_name" placeholder="Last Name*" required></div>
    <div class="field-wrapper"><label for="email">Email</label><input type="email" name="email" id="email" placeholder="Email*" required></div>
    <div class="field-wrapper">
      <label for="user_year" class="visible"><span class="vertically-center">Your Birthdate</span></label>
      <select name="user_month" id="user_month" required>
        <option value="">Month*</option>
        <?php foreach (range(1,12) as $month) : ?>
        <option value="<?php print $month; ?>"><?php print date("F", mktime(0,0,0,$month,10)); ?></option>
        <?php endforeach; ?>
      </select>
      <select name="user_day" id="user_day" required>
        <option value="">Day*</option>
        <?php foreach (range(1,31) as $day) : ?>
        <option value="<?php print $day; ?>"><?php print $day; ?></option>
        <?php endforeach; ?>
      </select>
      <select name="user_year" id="user_year" required>
        <option value="">Year*</option>
        <?php foreach (array_reverse(range(1900, date(Y))) as $year) : ?>
        <option value="<?php print $year; ?>"><?php print $year; ?></option>
        <?php endforeach; ?>
      </select>
    </div>
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
    <div class="field-wrapper field-wrapper-story-year clearfix">
      <label class="visible"><span class="vertically-center">Approximate Year This Story Happened</span>
        <select name="story_year" id="story_year" class="pull-right" required>
          <option value="">Year</option>
          <?php foreach (array_reverse(range(1950, date(Y))) as $year) : ?>
          <option value="<?php print $year; ?>"><?php print $year; ?></option>
          <?php endforeach; ?>
        </select>
      </label>
    </div>
    <div class="field-wrapper"><label for="story_body">Your Story</label><textarea name="story_body" id="story_body" cols="30" rows="10" placeholder="Tell us your story" maxlength="400" required></textarea></div>
  </fieldset>
  <fieldset>
    <legend>Pictures Make The Story</legend>
    <p>Drag and drop image files into the dotted lines to upload.</p>
    <input type="hidden" name="image_link">
    <input type="hidden" name="teacher_image_link">
    <div id="sys-image-user" class="sys-image sys-image-user left">
      <div class="sys-image-content">
        <p><strong>Your Picture</strong><br /><small>(recommended)</small></p>
        <p class="sys-image-description"><small>Preferably a yearbook or school picture. Alternately one during the time period.</small></p>
      </div>
    </div>
    <div id="sys-image-teacher" class="sys-image sys-image-teacher right">
      <div class="sys-image-content">
        <p><strong>Your Teacher's Picture</strong><br /><small>(recommended)</small></p>
        <p class="sys-image-description"><small>A picture of the teacher or the school.</small></p>
      </div>
    </div>
  </fieldset>
  <fieldset>
    <div class="field-wrapper clearfix"><input type="checkbox" class="pull-left" id="email_subscribe" name="email_subscribe"><label for="email_subscribe" class="visible">I would like to receive TakePart's newsletter on topics related to teaching and education</label></div>
    <div class="field-wrapper field-wrapper-terms-agree"><input type="checkbox" id="terms_agree" name="terms_agree" required><label for="terms_agree" class="visible">I have read and agree to the <a href="#">content submission agreement</a></label></div>
  </fieldset>
  <p class="clearfix">
    <input type="button" id="sys-preview" class="sys-button left" value="Preview Story" />
    <input type="submit" id="sys-submit" class="sys-button sys-button-submit right" value="Submit Story" />
  </p>
  <p class="fine-print clearfix">By clicking "Submit Story" above, you agree to TakePart's <?php print l('Terms of Use', 'terms-of-use', array('attributes' => array('target' => '_blank'))); ?> and <?php print l('Privacy Policy', 'privacy-policy', array('attributes' => array('target' => '_blank'))); ?></p>
</form>
