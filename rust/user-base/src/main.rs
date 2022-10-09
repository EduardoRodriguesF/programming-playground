struct User {
    name: String,
    age: u8,
}

impl User {
    fn new(name: String, age: u8) -> Self {
        User { name, age }
    }
}

fn main() {
    let mut users: Vec<User> = Vec::new();

    users.push(User::new(String::from("user A"), 29));
    users.push(User::new(String::from("user B"), 17));
    users.push(User::new(String::from("user C"), 92));

    for user in &mut users {
        println!("User {} has {}... aging one year now!", user.name, user.age);
        
        // usually would need to dereference it, but apparantly not...
        // *user.age += 5; results in error
        user.age += 1;
    }

    loop {
        println!("Enter an index to access user infos");

        let mut index = String::new();

        std::io::stdin().read_line(&mut index).expect("Failed to read line!");

        let index: usize = index.trim().parse().expect("Not a number!");

        match users.get(index) {
            Some(user) => println!("You accessed {}, a {} years old user!", user.name, user.age),
            None => println!("Not a valid index!"),
        }
    }
}
