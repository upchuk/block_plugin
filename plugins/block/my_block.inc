<?php

$plugin = array(
  'title' => t('This is my block'),
);

/**
 * Returns a renderable array that represents the block content
 */
function block_plugin_my_block_view($delta) {
  return array(
    '#type' => 'markup',
    '#markup' => 'Yo block!'
  );
}

/**
 * Returns a form to be used as the block configuration form
 *
 * @param $delta
 * @return array
 */
function block_plugin_my_block_configure($delta) {
  $form = array();
  $form['my_custom_field'] = array(
    '#type' => 'textfield',
    '#title' => t('My custom field'),
    '#default_value' => variable_get($delta, '')
  );

  return $form;
}

/**
 * Returns a form to be used as the block configuration form
 * @param $block
 */
function block_plugin_my_block_save($block) {
  variable_set($block['delta'], $block['my_custom_field']);
}

