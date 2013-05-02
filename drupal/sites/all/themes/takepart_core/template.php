<?php


// pretty print arrays
function _l($someArray, $prepend = '') {
    echo "<hr />";
    if ( !is_array($someArray) && !is_object($someArray) ) {
      echo '<div class="data"><span class="value">' . htmlspecialchars($v) . '</span></div>';
    }

    $someArray = (array)$someArray;
    $iterator = new RecursiveIteratorIterator(new RecursiveArrayIterator($someArray), RecursiveIteratorIterator::SELF_FIRST);
    foreach ($iterator as $k => $v) {
        //$indent = str_repeat('&nbsp;', 10 * $iterator->getDepth());
        // Not at end: show key only
        if ($iterator->hasChildren()) {
            //echo "$k :<br>";
        // At end: show key, value and path
        } else {
            for ($p = array(), $i = 0, $z = $iterator->getDepth(); $i <= $z; $i++) {
                $b = '[';
                $e = ']';
                $c = $iterator->getSubIterator($i)->current();
                if ( is_object($c) ){
                  $b = '{';
                  $e = '}';
                }
                $p[] = $b . '\'' . $iterator->getSubIterator($i)->key() . '\'' . $e;
            }
            $path = $prepend . implode('', $p);
            echo '<div class="data"><span class="key">' . $path . ': <span class="value">' . htmlspecialchars($v) . '</span></div>';
        }
    }
}