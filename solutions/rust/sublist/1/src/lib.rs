#[derive(Debug, PartialEq, Eq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}

// [1, 2, 3], [1, 2, 3, 4, 5, 6] ->

fn is_sublist(first_list: &[i32], second_list: &[i32]) -> bool {
    if second_list.len() < first_list.len() {
        return false;
    }

    for i in first_list {
        if second_list.contains(i) {
            continue;
        } else {
            return false;
        }
    }

    true
}

pub fn sublist(first_list: &[i32], second_list: &[i32]) -> Comparison {
    if first_list == second_list {
        Comparison::Equal
    } else if is_sublist(first_list, second_list) {
        Comparison::Superlist
    } else if is_sublist(second_list, first_list) {
        Comparison::Sublist
    } else {
        Comparison::Unequal
    }
}
