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

    for user in &users {
        println!("User {} has {}", user.name, user.age);
    }

    println!("Most recent user: {}", &users.last().unwrap().name);
    println!("First user: {}", &users.first().unwrap().name);
}
