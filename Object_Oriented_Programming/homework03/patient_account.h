# ifndef PATIENT_ACCOUNT_H
# define PATIENT_ACCOUNT_H

class Patient_account
{
	private:
		int days;
		int rate;
		int total;
		
	public:
		Patient_account(int day = 0, int room = 0);
		
		void days_cal(int d, int r);
		void fee_cal(int f);
		
		int get_days() const;
		int get_rate() const;
		int get_total() const;
};

# endif
