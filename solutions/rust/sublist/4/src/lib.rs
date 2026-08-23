#[derive(Debug, PartialEq, Eq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}

fn is_sublist(first_list: &[i32], second_list: &[i32]) -> bool {
    first_list.is_empty()
        || (first_list <= second_list)
            && second_list
                .windows(first_list.len())
                .any(|window| window == first_list)
}

pub fn sublist(first_list: &[i32], second_list: &[i32]) -> Comparison {
    if first_list == second_list {
        Comparison::Equal
    } else if is_sublist(second_list, first_list) {
        Comparison::Superlist
    } else if is_sublist(first_list, second_list) {
        Comparison::Sublist
    } else {
        Comparison::Unequal
    }
}
