<form id="sys-form" class="sys-form" action="/">
  <fieldset>
    <legend>Your Story</legend>
    <div class="field-wrapper field-wrapper-story-year clearfix">
      <label class="visible"><span class="vertically-center">Approximate Year This Story Happened</span>
        <select name="story_year" id="story_year" class="pull-right" required>
	  <option value="">Year*</option>
          <?php foreach (array_reverse(range(1950, date(Y))) as $year) : ?>
          <option value="<?php print $year; ?>"><?php print $year; ?></option>
          <?php endforeach; ?>
        </select>
      </label>
    </div>
    <div class="field-wrapper"><label for="story_body">Your Story</label><textarea name="story_body" id="story_body" cols="30" rows="8" placeholder="Tell Us Your Story" maxlength="2500" required></textarea></div>
  </fieldset>
    
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
  </fieldset>
  <fieldset>
    <legend>Your School</legend>
    <input type="hidden" name="school_id" id="school_id" value="0">
    <input type="hidden" name="school_city" id="school_city" value="">
    <div class="field-wrapper">
      <label for="school_state">State</label>
      <select name="school_state" id="school_state" required>
	<option value="">State*</option><option value="AL">AL</option><option value="AK">AK</option><option value="AZ">AZ</option><option value="AR">AR</option><option value="CA">CA</option><option value="CO">CO</option><option value="CT">CT</option><option value="DE">DE</option><option value="DC">DC</option><option value="FL">FL</option><option value="GA">GA</option><option value="HI">HI</option><option value="ID">ID</option><option value="IL">IL</option><option value="IN">IN</option><option value="IA">IA</option><option value="KS">KS</option><option value="KY">KY</option><option value="LA">LA</option><option value="ME">ME</option><option value="MD">MD</option><option value="MA">MA</option><option value="MI">MI</option><option value="MN">MN</option><option value="MS">MS</option><option value="MO">MO</option><option value="MT">MT</option><option value="NE">NE</option><option value="NV">NV</option><option value="NH">NH</option><option value="NJ">NJ</option><option value="NM">NM</option><option value="NY">NY</option><option value="NC">NC</option><option value="ND">ND</option><option value="OH">OH</option><option value="OK">OK</option><option value="OR">OR</option><option value="PA">PA</option><option value="RI">RI</option><option value="SC">SC</option><option value="SD">SD</option><option value="TN">TN</option><option value="TX">TX</option><option value="UT">UT</option><option value="VT">VT</option><option value="VA">VA</option><option value="WA">WA</option><option value="WV">WV</option><option value="WI">WI</option><option value="WY">WY</option>
      </select>
      <label for="school_name">School Name</label>
      <input type="text" name="school_name" id="school_name" class="input-school-name" placeholder="Name Of School Where You Had This Teacher*" disabled="disabled" required>
    </div>
    <p class="school-name-instructions">Type at least one full word from the name of your school and then select it from the list.</p>
  </fieldset>

  <fieldset>
    <legend>OPTIONAL: Pictures Make The Story!</legend>
    <div id="sys-image-user" class="sys-image sys-image-user left">
      <label class="sys-image-content" for="user_image">
	<p><strong>Your Picture</strong></p>
	<p class="sys-image-description"><small>Upload a photo you own or have the rights to here (a yearbook photo, family photo, etc.).</small></p>
	<p class="sys-upload-buttons"><span>Upload</span></p>
      </label>
      <input type="file" name="file" id="user_image">
      <input type="hidden" id="user_image_id" name="user_image_id">
      <input type="hidden" id="user_image_link" name="user_image_link">
    </div>
    <div id="sys-image-teacher" class="sys-image sys-image-teacher right">
      <label class="sys-image-content" for="teacher_image">
	<p><strong>Your Teacher's Picture</strong></p>
	<p class="sys-image-description"><small>Upload a photo of the teacher or school featured in your story that you own or have the rights to here.</small></p>
	<p class="sys-upload-buttons"><span>Upload</span></p>
      </label>
      <input type="file" name="file" id="teacher_image">
      <input type="hidden" id="teacher_image_id" name="teacher_image_id">
      <input type="hidden" id="teacher_image_link" name="teacher_image_link">
    </div>
  </fieldset>
  <fieldset>
    <div class="field-wrapper clearfix"><input type="checkbox" class="pull-left" id="email_subscribe" name="email_subscribe"  checked="checked"><label for="email_subscribe" class="visible">I would like to receive TakePart's newsletter on topics related to teaching and education and email updates on the TEACH campaign and contest.</label></div>
    <div class="field-wrapper field-wrapper-terms-agree"><input type="checkbox" id="terms_agree" name="terms_agree" required><label for="terms_agree" class="visible">I have read and agree to the <a class="teach-text-lightbox" href="/teach-official-rules">Official Rules</a>.</label></div>
  </fieldset>
  <p class="clearfix">
    <input type="button" id="sys-preview" class="sys-button left" value="Preview Story" />
    <input type="submit" id="sys-submit" class="sys-button sys-button-submit right" value="Submit Story" />
  </p>
  <p class="fine-print clearfix">By clicking "Submit Story" above, you agree to TakePart's <?php print l('Terms of Use', 'terms-of-use', array('attributes' => array('target' => '_blank'))); ?> and <?php print l('Privacy Policy', 'privacy-policy', array('attributes' => array('target' => '_blank'))); ?></p>
</form>
<script type="text/x-microtemplate" id="story_template">
  <div class="sys-story-modal">
    <h2 class="sys-story-headline"><span>Teacher Stories From <span class="teach-logo">Teach</span></span></h2>
    <div class="sys-story-teacher-image-wrapper"><img id="sys-story-teacher-image" class="sys-story-teacher-image" src="http://placehold.it/350x410&text=loading..." data-src="<%=teacher_image_id%>.jpg" data-width="350" data-height="410" data-crop="fill" data-gravity="faces"></div>
    <div class="content">
      <h3>Teacher</h3>
      <h2 class="sys-story-subhead"><%=teacher_first_name%> <%=teacher_last_name%></h2>
      <div class="sys-story-user-image-wrapper"><img id="sys-story-user-image" class="sys-story-user-image" src="http://placehold.it/150x200&text=loading..." data-src="<%=user_image_id%>.jpg" data-width="150" data-height="200" data-crop="fill" data-gravity="faces"></div>
      <h3>School</h3>
      <p>
        <%=school_name%><br />
        <% if (school_city ) { %><%=school_city%>, <% } %>
        <%=school_state%><br />
        <%=story_year%></p>
      <h3>Submitted By</h3>
      <p><%=first_name%> <%=last_name%></p>
      <p><%=story_body%></p>
    </div>
  </div>
</script>
