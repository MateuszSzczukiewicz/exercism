pub fn reverse(input: &str) -> String {
    let mut reversed_input = String::from("");

    for i in input.chars() {
        reversed_input.insert(0, i);
    }

    reversed_input.to_string()
}
