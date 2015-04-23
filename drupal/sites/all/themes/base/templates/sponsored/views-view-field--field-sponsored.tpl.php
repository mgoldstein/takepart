<?php

print $row->field_field_sponsored[0]['raw']['tid'] ? '<span class="promoted sponsor-'.$row->field_field_sponsored[0]['raw']['tid'].'">Promoted</span>':'';
