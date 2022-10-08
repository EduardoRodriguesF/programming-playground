use std::io::stdin;

const MONTHS: &[&str] = &[
    "January",
    "February",
    "March",
    "April",
    "May",
    "August",
    "September",
    "October",
    "November",
    "December",
];

fn main() {
    let stdin = stdin();

    let mut index = String::new();

    println!("Enter a month index");

    stdin.read_line(&mut index).expect("Failed to read line");

    let index: usize = index.trim().parse().expect("Not a number!");

    if index > MONTHS.len() - 1 {
        println!("Index out of range!");
        return;
    }

    let month = MONTHS[index];

    println!("You accessed {month}!");
}
