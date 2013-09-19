<? $form = $variables['element']; ?>

<?= render($form['form_build_id']); ?>
<?= render($form['form_token']); ?>
<?= render($form['form_id']); ?>

<section>
  <header>
    <h3><?= render($form['about_you_heading']); ?></h3>
    <p><?= render($form['about_you_description']); ?></p>
  </header>
  <div class="textfields">
    <fieldset>
      <?= render($form['first_name']); ?>
    </fieldset>

    <fieldset>
      <?= render($form['last_name']); ?>
    </fieldset>

    <fieldset>
      <?= render($form['email']); ?>
    </fieldset>

    <fieldset class="date">
      <?= render($form['dob_month']); ?>
      <?= render($form['dob_year']); ?>
    </fieldset>

    <fieldset>
      <?= render($form['city']); ?>
    </fieldset>

    <fieldset>
      <?= render($form['state']); ?>
    </fieldset>
  </div>

    <h4><?= render($form['which_award_label']); ?></h4>
  <fieldset class="checks-radios">
    <input type="radio" name="which_award" value="lifestyle" class="form-radio" id="lifestyle_award" />
    <label for="lifestyle_award"><?= render($form['lifestyle_award_label']); ?></label>
    <?= render($form['lifestyle_award_description']); ?>
    
  </fieldset>
  <fieldset class="checks-radios">
    <input type="radio" name="which_award" value="pioneer" class="form-radio" id="pioneer_award" />
    <label for="pioneer_award"><?= render($form['pioneer_award_label']); ?></label>
    <?= render($form['pioneer_award_description']); ?>
  </fieldset>
</section>



<section>
  <header>
    <h3><?= render($form['your_video_heading']); ?></h3>
    <p><?= render($form['your_video_description']); ?></p>
  </header>
  <div class="textfields">
    <fieldset>
      <?= render($form['video_link']); ?>
    </fieldset>
  </div>
</section>

<section>
  <header>
    <h3><?= render($form['submission_heading']); ?></h3>
    <p><?= render($form['submission_description']); ?></p>
  </header>
  <fieldset class="checks-radios">
    <?= render($form['newsletter_opt_in']); ?>
  </fieldset>
  <fieldset class="checks-radios">
    <?= render($form['contest_rules_opt_in']); ?>
  </fieldset>
  <?= render($form['terms_of_service']); ?>
  <?= render($form['submit']); ?>
</section>
