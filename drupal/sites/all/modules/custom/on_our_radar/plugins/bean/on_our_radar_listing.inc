<?php

class OnOurRadarBean extends BeanPlugin
{

    //Items in Link grouping:
    private $radar_lnk_cnt = 3;

    /**
     * Declares default block settings.
     */
    public function values()
    {
        $values = array(
            'settings' => array(
                'node_view_mode' => FALSE,
                'records_shown' => FALSE
            ),
            'radar_links' => array(
                'text' => '',
                'path' => ''
            )
        );
        return array_merge(parent::values(), $values);
    }

    /**
     * Builds extra settings for the block edit form.
     */
    public function form($bean, $form, &$form_state)
    {

        drupal_add_css(drupal_get_path('module', 'on_our_radar') . '/css/admin.css', array(
            'group' => CSS_DEFAULT,
            'type' => 'file'
        ));

        $form = array();

        if ($form_state['triggering_element']['#name'] == 'add') {
            $form_state['storage']['linkcount']++;
        }


        $form_state['storage']['linkcount'] = isset($form_state['storage']['linkcount']) ? $form_state['storage']['linkcount'] : (count($bean->radar_links) / $this->radar_lnk_cnt);

        $form['radar_links'] = array(
            '#type' => 'fieldset',
            '#tree' => TRUE,
            '#prefix' => '<div id="radar_links_wrapper">',
            '#suffix' => '</div>',
            '#title' => t('Links')
        );

        $linkcount = $form_state['storage']['linkcount'];

        if (substr($form_state['triggering_element']['#name'], 0, 6) == 'remove') {
            $itemnum = substr($form_state['triggering_element']['#name'], 6, strlen($form_state['triggering_element']['#name']));
            unset($bean->radar_links['link' . $i]);
            unset($bean->radar_links['title' . $i]);
            unset($bean->radar_links['topic' . $i]);
            $form_state['storage']['linkcount']--;
        }

        $i = 1;
        for ($x = 1; $x <= $linkcount; $x++) {

            $form['radar_links']['link' . $i]  = array(
                '#type' => 'textfield',
                '#title' => t('Link ' . $i),
                '#default_value' => $bean->radar_links['link' . $x],
                '#value' => isset($form_state['values']['radar_links']['link' . $x]) ? $form_state['values']['radar_links']['link' . $x] : $bean->radar_links['link' . $x]
            );
            $form['radar_links']['title' . $i] = array(
                '#type' => 'textfield',
                '#title' => t('Title ' . $i),
                '#default_value' => $bean->radar_links['title' . $x],
                '#value' => isset($form_state['values']['radar_links']['title' . $x]) ? $form_state['values']['radar_links']['title' . $x] : $bean->radar_links['title' . $x]
            );
            $form['radar_links']['topic' . $i] = array(
                '#type' => 'textfield',
                '#title' => t('Topic ' . $i),
                '#default_value' => $bean->radar_links['topic' . $x],
                '#value' => isset($form_state['values']['radar_links']['topic' . $x]) ? $form_state['values']['radar_links']['topic' . $x] : $bean->radar_links['topic' . $x],
                '#attributes' => array(
                    'class' => array(
                        'last'
                    )
                )
            );
            if ($i > 1) {
                $form['radar_links']['remove_link' . $i] = array(
                    '#type' => 'button',
                    '#value' => t('Remove'),
                    '#name' => 'remove' . $i,
                    '#href' => '',
                    '#ajax' => array(
                        'callback' => 'on_our_radar_ajax_remove_link',
                        'wrapper' => 'radar_links_wrapper'
                    )
                );
            }

            if ($itemnum != $x) {
                $i++;
            }

        }

        $form['add_link'] = array(
            '#type' => 'button',
            '#value' => t('Add a Link'),
            '#name' => 'add',
            '#href' => '',
            '#ajax' => array(
                'callback' => 'on_our_radar_ajax_add_link',
                'wrapper' => 'radar_links_wrapper'
            )
        );

        return $form;
    }

    /**
     * Displays the bean.
     */
    public function view($bean, $content, $view_mode = 'default', $langcode = NULL)
    {
        $elements = array();
        for ($i = 1; $i <= count($bean->radar_links) / $this->radar_lnk_cnt; $i++) {
            $elements[$i]          = array();
            $elements[$i]['topic'] = $bean->radar_links['topic' . $i];
            $elements[$i]['link']  = $bean->radar_links['link' . $i];
            $elements[$i]['title'] = $bean->radar_links['title' . $i];
        }
        $content['radar_links']['#markup'] = theme('on_our_radar', array(
            'links' => $elements
        ));
        return $content;
    }
}

function on_our_radar_ajax_add_link($form, $form_state)
{
    return $form['radar_links'];
}

function on_our_radar_ajax_remove_link($form, $form_state)
{
    return $form['radar_links'];
}
