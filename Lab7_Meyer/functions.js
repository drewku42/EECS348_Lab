// FUNCTIONALITY FOR PRACTICE 2
function validate() {
    var pass1 = document.getElementById("pass1").value;
    var pass2 = document.getElementById("pass2").value;


    if (pass1.length < 8) {
        alert("The first password must be at least 8 characters.")
    } else if (pass2.length < 8) {
        alert("The second password must be at least 8 characters.")
    } else if (pass1 != pass2) {
        alert("Passwords can not be validated. Must match.")
    } else {
        alert("Passwords validated.")
    }
}

var picture_index = 0;

function prev() {
    picture_index = ((picture_index + 5) - 1) % 5
    var picture_uri = `pictures/${picture_index}.jpeg`
    document.getElementById("picture").src = picture_uri
}

function next() {
    picture_index = (picture_index + 1) % 5
    var picture_uri = `pictures/${picture_index}.jpeg`
    document.getElementById("picture").src = picture_uri
}


// FUNCTIONALITY FOR PRACTICE 3
function alert_paragraph_color() {
    var border_R = document.getElementById("border_R").value;
    var border_G = document.getElementById("border_G").value;
    var border_B = document.getElementById("border_B").value;
    var border_width = document.getElementById("border_width").value;
    var bg_R = document.getElementById("bg_R").value;
    var bg_G = document.getElementById("bg_G").value;
    var bg_B = document.getElementById("bg_B").value;

    var tag = document.getElementById("paragraph");
    tag.style.borderColor = `rgb(${border_R},${border_G},${border_B})`;
    tag.style.borderWidth = border_width
    tag.style.backgroundColor = `rgb(${bg_R},${bg_G},${bg_B})`;
}

// FUNCTIONALITY FOR PRACTICE 4

document.getElementById('table-form').addEventListener('submit', function(e) {
    e.preventDefault(); //prevent the form from being submitted the traditional way

    var number = document.querySelector('input[name="number"]').value;

    var xhr = new XMLHttpRequest();
    xhr.open('GET', 'table.php', true);  //configure it: GET-request for the table.php
    xhr.send(); //send request
    xhr.onload = function() {
        if (xhr.status != 200) {
            alert('Error ${xhr.status}: ${xhr.statusText}');
        } else {
            document.getElementById('table-container').innerHTML = xhr.response;
        }
    };
});

// load the table when the window loads
window.onload = loadTable;