/**
 * @file
 * A JavaScript file for handling CIC menu.
 *
 */

(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.cicMenuToggle = {
    attach: function (context, settings) {
      $('body').once('mobileMenuToggle', function () {
        var $body = $('body');
        $('.campaign-experience .toggle-menu.toggle-left ,#cic-menu .i-close-x').click(function () {
          if ($body.hasClass('cic-menu-show')) {
            $body.removeClass('cic-menu-show');
            $('#cic-menu').fadeOut();
          }
          else {
            //Display the menu item that matches the current node
            expandCicMenu();
            $body.addClass('cic-menu-show');
            $('#cic-menu').fadeIn();
          }
        });
      });
    }
  }

  Drupal.behaviors.cicMenuBehaviors = {
    attach: function (context, settings) {
      $('body').once('cicMenuBehaviors', function () {
      /* Show/hide child menu and prevent parent link from clicking - CIC menu */
      $('#cic-menu .content-menu ul > li.expanded > a').on('click', function (e) {
        if (!$(this).parent().hasClass('show')) {
          //Collapse any open/active items.
          $('#cic-menu .content-menu li.expanded').each(function(){
            $(this).removeClass('show');
            $(this).children('ul.menu').slideUp();
          });
          $(this).parent().addClass('show');
          $(this).next().slideDown();
          e.preventDefault();
        }
        else {
          $(this).parent().removeClass('show');
          $(this).next().slideUp();
          e.preventDefault();
        }
      });
    });
    }
  }

/* expand the CIC menu to display the current article */
function expandCicMenu() {
  //On campaign pages, just expand the first parent link
  if ($('body.campaign-display').length != 0) {
     $('#cic-menu .content-menu li.expanded.first').addClass('show');
     $('#cic-menu .content-menu li.expanded.first').children('ul.menu').slideDown();
     return false;
  }
  //Collapse any open menu items
  $('#cic-menu .content-menu li.expanded').each(function() {
    $(this).removeClass('show');
    $(this).children('ul.menu').slideUp();
  });
  //remove any previous link that has current-node class
  $('#cic-menu .content-menu li.is-leaf a').removeClass('current-node');

  active_url = window.location.href;
  //Loop through the content menu link and match the url
  $('#cic-menu .content-menu li.is-leaf a').each(function() {
    $this = $(this);
    var href = $this.attr('href');
    //Convert relative links to absulute
    if (href.substr(0,7) != 'http://' && href.substr(0,8) != 'https://' && href.substr(0,2) != '//') {
      //Append the host file
      href = 'http://' + window.location.host + href;
    }
    if (active_url == href) {
      $(this).addClass('current-node');
      //Does the link have a parent?
      if ($this.parents('li.expanded').length != 0) {
        parent_link = $this.parents('li.expanded');
        //Expand the parent menu item
        parent_link.addClass('show');
        parent_link.children('ul.menu').slideDown();
      }
      return false;
    }
  });
}

})(jQuery, Drupal, this, this.document);
