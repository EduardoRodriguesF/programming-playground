use std::io::stdin;

const MONTHS: &[(&str, usize)] = &[
    ("January", 31),
    ("February", 28),
    ("March", 31),
    ("April", 30),
    ("May", 31),
    ("June", 30),
    ("July", 31),
    ("August", 31),
    ("September", 30),
    ("October", 31),
    ("November", 30),
    ("December", 31),
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

    let (month, days) = MONTHS[index];

    println!("You accessed {month}, which has {days} days!\n");

    println!("Other months:");
    for item in MONTHS {
        let (month, days) = item;

        println!("{month}, {days}");
    }
}
