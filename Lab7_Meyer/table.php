<?php
// get user input from form
$number = intval($_POST['number']);

// generate the multiplication table
function generate_table($n) {
    $table = '<table border="1">';
    for ($i = 0; $i <= $n; $i++) {
        $table .= '<tr>';
        for ($j = 0; $j <= $n; $j++) {
            if ($i == 0 && $j == 0) {
                $table .= '<td></td>';
            }
            elseif ($i == 0) {
                $table .= '<td>' . $j . '</td>';
            }
            elseif ($j == 0) {
                $table .= '<td>' . $i . '</td>';
            }
            else {
                $table .= '<td>' . ($i * $j) . '</td>';
            }
        }
        $table .= '</tr>';
    }
    $table .= '</table>';
    return $table;
}

// generate the table and echo the result
echo generate_table($number);
?>

