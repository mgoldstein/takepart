This adds a way to capture the referring URL when submitting a contact us form.

This adds a new text field, hides it, and sets the default value to the incoming referrer

Installation:
-------------

1) Enable new module takepart_contact.module

2) On contact form:
  delete the field referring_page
  create new field Referring URL, field
   name: referring_url
   type: Textfield

  remove the field "Agent Info", which is not used.